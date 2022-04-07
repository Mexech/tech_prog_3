#include "Shape.h"

class Circle: public Shape{
    private: 
        float radius;
    public:
        Circle(float r);
        float Area();
        float Perimeter();
        void Display(FILE *fp = stdout);
        const char* toName();
};