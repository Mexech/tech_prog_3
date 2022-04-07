#include <iostream>
#include "Triangle.h"
#include "math.h"

using namespace std;

Triangle::Triangle(float a, float b, float c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

float Triangle::Area() {
    float s = Perimeter()/2;
    return sqrt(s*(s - a)*(s - b)*(s - c));
} 

float Triangle::Perimeter() {
    return a + b + c;
}

void Triangle::Display(FILE *fp) {
    fprintf(fp, "Triangle:\n\ta = %.2f\n\tb = %.2f\n\tc = %.2f\n\tarea = %.2f\n\tperimeter = %.2f\n", a, b, c, Area(), Perimeter());
}

const char* Triangle::toName() {
    return "Triangle";
};