#pragma once
class Shape {
    private:
        float *coords;
        int n;
        static int total;
    public:
        Shape(float *cs = nullptr, int n = 0);
        ~Shape();
        virtual float Area();
        virtual float Perimeter();
        virtual void Display(FILE *fp = stdout);
        virtual const char* toName();
};