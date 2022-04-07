#include "Shape.h"

class Trapezoid: public Shape {
    private: 
        float a, b, c, d;
    public:
        Trapezoid(float a, float b, float c, float d);
        float Area();
        float Perimeter();
        void Display(FILE *fp = stdout);
        const char* toName();
};