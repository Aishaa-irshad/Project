#include "Brightness.h"
#include "Image.h"
#include "Pixel.h"

Brightness::Brightness(int amount):
 Filter("03", "Brightness Adjust", "Pixel Transform"), delta(amount){
}
Brightness::~Brightness() {
}

void Brightness::apply(Image& image) const{
    cout <<"Applying Brightness Filter with adjustment: " << delta << endl;
    
    for (int i = 0; i <image.getHeight();i++){
        for (int j = 0; j<image.getWidth(); j++){
            Pixel& pixel = image.at(i,j);
//RGB value
            int r = pixel.getRed();
            int g = pixel.getGreen();
            int b = pixel.getBlue();
//adjust brightness (clamping)
            pixel.setRed(r+ delta);
            pixel.setGreen(g+ delta);
            pixel.setBlue(b+ delta);
        }
    }
    cout << "Brightness filter applied." << endl;
}
void Brightness::setDelta(int d){
    delta = d;
}
int Brightness::getDelta() const{
    return delta;
}
Filter* Brightness::clone() const {
    return new Brightness(*this);
}