#include <iostream>
#include "Circle.h"
#include "math.h"

using namespace std;

Circle::Circle(float r) {
    radius = r;
}

float Circle::Area() {
    return M_PI*pow(radius, 2);
} 

float Circle::Perimeter() {
    return 2*M_PI*radius;
}

void Circle::Display(FILE *fp) {
    fprintf(fp, "Circle:\n\tradius = %.2f\n\tarea = %.2f\n\tperimeter = %.2f\n", radius, Area(), Perimeter());
}

const char* Circle::toName() {
    return "Circle";
};