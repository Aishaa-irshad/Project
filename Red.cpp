#include "Red.h"
#include "Image.h"
Red::Red() : Filter("05", "Red Channel Only", "Pixel Transform") {
}

Red::~Red(){
}
void Red::apply(Image& image)const{
    cout << "Applying Red Filter." << endl;
    for (int i = 0; i < image.getHeight(); ++i){
        for (int j = 0; j < image.getWidth(); ++j){
            Pixel& pixel = image.at(i, j);
            pixel.setGreen(0);
            pixel.setBlue(0);
        }
    }
    cout << "Red Filter applied." << endl;
}
Filter* Red::clone() const {
    return new Red(*this);
}
