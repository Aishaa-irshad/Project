#ifndef PIXEL_H
#define PIXEL_H
#include <iostream>
using namespace std;

class Pixel{
private:
    int red;
    int green;
    int blue;
public:
    Pixel();
    Pixel(int r, int g, int b);

//getters
    int getRed() const;
    int getGreen() const;
    int getBlue() const;
//setters
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);
//static 
    static int clamp(int value);
///oper overloading
    Pixel operator+(const Pixel& other) const;
    friend ostream& operator<<(ostream& os,const Pixel& pixel);
    void getASCII();
};

#endif