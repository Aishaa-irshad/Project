#include "Blue.h"
#include "Image.h"

Blue::Blue(): Filter("07", "Blue Channel", "Pixel Transform"){
}
Blue::~Blue(){
}

void Blue::apply(Image& image) const{
    cout << "Applying Blue Filter." << endl;
    for (int i = 0; i < image.getHeight(); ++i){
        for (int j = 0; j < image.getWidth(); ++j){
            Pixel& pixel = image.at(i, j);
            pixel.setRed(0);
            pixel.setGreen(0);
        }
    }
    cout << "Blue Filter applied." << endl;
}

Filter* Blue::clone() const{
    return new Blue(*this);
}