#include "Green.h"
#include "Image.h"

Green::Green() : Filter("06", "Green Channel", "Pixel Transform") {
}
Green::~Green() {
}

void Green::apply(Image& image) const{
    cout << "Applying Green Filter." << endl;
    for (int i = 0; i < image.getHeight(); ++i){
        for (int j = 0; j < image.getWidth(); ++j){
            Pixel& pixel = image.at(i, j);
            pixel.setRed(0);
            pixel.setBlue(0);
        }
    }
    cout << "Green Filter applied." << endl;
}
Filter* Green::clone() const {
    return new Green(*this);
}