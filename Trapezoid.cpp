#include <iostream>
#include "Trapezoid.h"
#include "math.h"

using namespace std;

Trapezoid::Trapezoid(float a, float b, float c, float d) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

float Trapezoid::Area() {
    return c*(a + b)/2*sqrt(1 - pow(((pow(b - a, 2)+c*c - d*d)/(2*c*(b - a))), 2));
} 

float Trapezoid::Perimeter() {
    return a + b + c + d;
}

void Trapezoid::Display(FILE *fp) {
    fprintf(fp, "Trapezoid:\n\ta = %.2f\n\tb = %.2f\n\tc = %.2f\n\td = %.2f\n\tarea = %.2f\n\tperimeter = %.2f\n", a, b, c, d, Area(), Perimeter());
}

const char* Trapezoid::toName() {
    return "Trapezoid";
};