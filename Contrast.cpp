#include "Contrast.h"
#include "Image.h"
#include "Pixel.h"

Contrast::Contrast() : Filter("04", "Contrast Stretch", "Pixel Transform") {
}
Contrast::~Contrast() {
}
void Contrast::apply(Image& image) const{
    if(image.isEmpty()){
        return;
    }
    cout << "Applying contrast stretch filter. "<< endl;
//find max,min
    int minR = 255, maxR = 0;
    int minG = 255, maxG = 0;
    int minB = 255, maxB = 0;

    for(int i=0; i<image.getHeight(); i++) {
        for(int j=0; j<image.getWidth(); j++) {
            Pixel & pixel = image.at(i, j);
//rgb value
            int r = pixel.getRed();
            int g = pixel.getGreen();
            int b = pixel.getBlue();
//updating min
            if(r<minR){
                minR = r;
            }
            if(g <minG){
                minG = g;
            }
            if(b <minB){
                minB = b;
            }
//updating max
            if(r > maxR){
                maxR = r;
            }
            if(g> maxG){
                maxG = g;
            }
            if(b > maxB){
                maxB = b;
            }
    }
}
//contrast stretch
    for(int i=0; i<image.getHeight(); i++) {
        for(int j=0; j<image.getWidth(); j++) {
            Pixel & pixel = image.at(i, j);
//rgb value
            if(maxR>minR){
                pixel.setRed(((pixel.getRed()- minR)*255)/(maxR-minR));
            }
            if(maxG>minG){
                pixel.setGreen(((pixel.getGreen()- minG)*255)/(maxG-minG));
            }
            if(maxB>minB){
                pixel.setBlue(((pixel.getBlue()- minB)*255)/(maxB-minB));
            }
        }
    }
    cout << "Contrast stretch filter applied." << endl;
}

Filter* Contrast::clone() const{
    return new Contrast(*this);
}