#include "Invert.h"
#include "Image.h"
Invert::Invert() : Filter("02", "Invert", "Pixel Transform") {
}

Invert::~Invert() {
}
void Invert::apply(Image& image) const{
    cout <<"Applying Invert Filter." << endl;
    
    for (int i = 0; i <image.getHeight();i++) {
        for (int j = 0; j<image.getWidth(); j++) {
            Pixel& pixel = image.at(i,j);

//RGB value
            int r = pixel.getRed();
            int g = pixel.getGreen();
            int b = pixel.getBlue();
//invert each (255-value)
            pixel.setRed(255 - r);
            pixel.setGreen(255 - g);
            pixel.setBlue(255 - b);
        }
    }
    cout << "Invert filter applied." << endl;
}
Filter* Invert::clone() const {
    return new Invert(*this);
}