#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Trapezoid.h"
#include "Triangle.h"

using namespace std;

#define GROW 1.5

const char *menu[2] = {"Load shape parameters from 'shapes.in'?(Y/N)\n",
                       "1: append shape; 2: append circle; 3: append triangle; 4: append trapezoid; 5: append rectangle;\n6: remove shape; 7: display shape parameters; 8: display list of shapes; 9: save shapes to 'shapes.out'; h: help\n"};

void in() {
    printf(">> ");
}

void help(int type = 1) {
    printf(menu[type]);
}

int getInt(const char *msg = "Type the value:\n") {
    int result;
    printf(msg);
    in();
    scanf("%d", &result);
    return result;
}

float getFloat(const char *msg = "Type the value:\n", FILE *fp = stdin) {
    float result;
    if (fp == stdin) {
        printf(msg);
        in();
        fscanf(fp, "%f", &result);
    } else 
        fscanf(fp, "%f\n", &result);
    return result;
}

char getChar(FILE *fp = stdin) {
    char result;
    if (fp == stdin) {
        printf("Type the char:\n");
        in();
    }
    fscanf(fp, "%c\n", &result);
    return result;
}

int extend(Shape **shapes, int size, int current) {
    if (current == size) {
        int res = size*GROW;
        Shape **temp = new Shape*[res];
        for (int i = 0; i < size; i++) {
            temp[i] = shapes[i];
        }
        shapes = temp;
        return res;
    }
    return size;
}

int main() {
    Shape **shapes;
    int shapes_size = 0;
    int shape_i = 0;
    help(0);
    in();
    char c = tolower(getchar());
    if (c == 'y') {
        FILE *fp = fopen("shapes.in", "r");
        int amount = getFloat("", fp);
        shapes_size = amount;
        shapes = new Shape*[amount];
        for (int i = 0; i < amount; i++) {
            char type = getChar(fp);
            if (type == 'c') 
                shapes[shape_i++] = new Circle(getFloat("", fp));
            else if (type == 'r')
                shapes[shape_i++] = new Rectangle(getFloat("", fp), getFloat("", fp));
            else if (type == 's') {
                int pairs_num = getFloat("", fp);
                float coords[pairs_num*2];
                for (int i = 0; i < pairs_num*2; i++)
                    coords[i] = getFloat("", fp);
                shapes[shape_i++] = new Shape(coords, pairs_num);
            }
            else if (type == 'a')
                shapes[shape_i++] = new Trapezoid(getFloat("", fp), getFloat("", fp), getFloat("", fp), getFloat("", fp));
            else if (type == 'i')
                shapes[shape_i++] = new Triangle(getFloat("", fp), getFloat("", fp), getFloat("", fp));
            shapes[shape_i-1]->Display();
        }
    } else {
        shapes_size = 1;
        shapes = new Shape*[1];
    }
    help();
    while (1) {
        char c = getchar();
        if (c == '\n') 
            in();
        if (c == 'h')
            help();
        else if (c == '1') {
            shapes_size = extend(shapes, shapes_size, shape_i);
            int size = getInt("Type the amount of points\n");
            float coords[size*2] = {0};
            for (int i = 0; i < size*2; i+=2) {
                coords[i] = getFloat("Type x\n");
                coords[i+1] = getFloat("Type y\n");
            }
            shapes[shape_i++] = new Shape(coords, size);
        }
        else if (c == '2') {
            shapes_size = extend(shapes, shapes_size, shape_i);
            shapes[shape_i++] = new Circle(getFloat("Type radius\n"));
        }
        else if (c == '3') {
            shapes_size = extend(shapes, shapes_size, shape_i);
            shapes[shape_i++] = new Triangle(getFloat("Type side a\n"), getFloat("Type side b\n"), getFloat("Type side c\n"));
        }
        else if (c == '4') {
            shapes_size = extend(shapes, shapes_size, shape_i);
            shapes[shape_i++] = new Trapezoid(getFloat("Type base a\n"), getFloat("Type base b\n"), getFloat("Type side c\n"), getFloat("Type side d\n"));
        }
        else if (c == '5') {
            shapes_size = extend(shapes, shapes_size, shape_i);
            shapes[shape_i++] = new Rectangle(getFloat("Type side a\n"), getFloat("Type side b\n"));
        }
        else if (c == '6') {
            int num = getInt("Type the position to be removed(indexing starts at 0)\n");
            if (num >= shape_i) {
                printf("Out of range\n");
                continue;
            }
            delete shapes[num];
            for (int i = num; i < shape_i; i++)
                shapes[i] = shapes[i+1];
            shape_i--;
        }
        else if (c == '7') {
            int num = getInt("Type the position to be displayed(indexing starts at 0)\n");
            if (num >= shape_i) {
                printf("Out of range\n");
                continue;
            }
            shapes[num]->Display();
        }
        else if (c == '8') {
            for (int i = 0; i < shape_i; i++)
                printf("%d: %s\n", i, shapes[i]->toName());
        }
        else if (c == '9') {
            FILE *out = fopen("shapes.out", "w+");
            for (int i = 0; i < shape_i; i++)
                shapes[i]->Display(out);
            fflush(out);
        }
    }
    return 0;
}