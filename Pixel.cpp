#include "Pixel.h"

static char brightnessToChar(int brightness) {
    const char scale[] = " .:-=+*#@";
    int index = (brightness * 8) / 255;
    if (index < 0) {
        index = 0;
    }
    if (index > 8) {
        index = 8;
    }
    return scale[index];
}

Pixel::Pixel(): red(0), green(0),blue(0){}
Pixel::Pixel(int r,int g, int b){
    red = clamp(r);
    green = clamp(g);
    blue = clamp(b);
}

int Pixel::clamp(int value) {
    if (value < 0) {
        return 0;
    }
    if (value > 255) {
        return 255;
    }
    return value;
}
int Pixel::getRed() const{
    return red;
}
int Pixel::getGreen() const{
    return green;
}
int Pixel::getBlue() const{
    return blue;
}

void Pixel::setRed(int r){
    red = clamp(r);
}
void Pixel::setGreen(int g){
    green = clamp(g);
}
void Pixel::setBlue(int b){
    blue = clamp(b);
}

Pixel Pixel::operator+(const Pixel& other) const{
    Pixel result;
    result.setRed(clamp(red + other.red));
    result.setGreen(clamp(green + other.green));
    result.setBlue(clamp(blue + other.blue));
    return result;
}
ostream& operator<<(ostream& out, const Pixel& pixel){
    int brightness = (pixel.red + pixel.green + pixel.blue) / 3;
    out << brightnessToChar(brightness);
    return out;
}