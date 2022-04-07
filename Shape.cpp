#include <iostream>
#include "Shape.h"
#include "math.h"

using namespace std;

int Shape::total = 0;

Shape::Shape(float *cs, int n) {
    total++;
    coords = (float *)calloc(n*2, sizeof(float));
    this->n = n;
    for (int i = 0; i < n*2; i++)
        coords[i] = cs[i];
}

Shape::~Shape() {
    total--;
    free(coords);
}

float Shape::Area() {
    float left_sum = coords[2*n-2]*coords[1], right_sum = coords[0]*coords[2*n-1];
    for (int i = 0; i < n; i++) {
        left_sum += coords[2*i]*coords[2*i+3];
		right_sum += coords[2*i+2]*coords[2*i+1];
    }
    return abs(left_sum - right_sum)/2;
}

float Shape::Perimeter() {
    float res = sqrt(pow(coords[0] - coords[2*n - 2], 2) + pow(coords[1] - coords[2*n - 1], 2));
    for (int i = 0; i < n - 1; i++)
        res += sqrt(pow(coords[2*i + 2] - coords[2*i], 2) + pow(coords[2*i + 3] - coords[2*i + 1], 2));
    return res;
}

void Shape::Display(FILE *fp) {
    fprintf(fp, "Shape:");
    for (int i = 0; i < n; i++)
        fprintf(fp, "\n\tx%d = %.2f, y%d = %.2f", i, coords[2*i], i, coords[2*i + 1]);
    fprintf(fp, "\n\tarea = %.2f\n\tperimeter = %.2f\n", Area(), Perimeter());
}

const char* Shape::toName() {
    return "Shape";
};