#include "Shape.h"

class Rectangle: public Shape {
    private: 
        float width, height;
    public:
        Rectangle(float w, float h);
        float Area() override;
        float Perimeter() override;
        void Display(FILE *fp = stdout) override;
        const char* toName();
};