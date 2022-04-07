#include <iostream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(float w, float h) {
    width = w;
    height = h;
}

float Rectangle::Area() {
    return width*height;
} 

float Rectangle::Perimeter() {
    return (width + height)*2;
}

void Rectangle::Display(FILE *fp) {
    fprintf(fp, "Rect:\n\twidth = %.2f\n\theight = %.2f\n\tarea = %.2f\n\tperimeter = %.2f\n", width, height, Area(), Perimeter());
}

const char* Rectangle::toName() {
    return "Rectangle";
};