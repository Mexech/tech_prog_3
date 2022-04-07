#include "Shape.h"

class Triangle: public Shape {
    private: 
        float a, b, c;
    public:
        Triangle(float a, float b, float c);
        float Area();
        float Perimeter();
        void Display(FILE *fp = stdout);
        const char* toName();
};