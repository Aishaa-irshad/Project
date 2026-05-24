#include "Grayscale.h"
#include "Image.h"

Grayscale::Grayscale() : Filter("01", "Grayscale", "Pixel Transform") {
}

Grayscale::~Grayscale() {
}
void Grayscale::apply(Image& image) const {
    cout << "Applying Grayscale filter." << endl;

    for (int i = 0; i < image.getHeight(); ++i) {
        for (int j = 0; j < image.getWidth(); ++j) {
//pixel at row and col
            Pixel& pixel = image.at(i, j);
//RGB value
            int r = pixel.getRed();
            int g = pixel.getGreen();
            int b = pixel.getBlue();
            int average = (r + g + b) / 3;

            pixel.setRed(average);
            pixel.setGreen(average);
            pixel.setBlue(average);
        }
    }
    cout << "Grayscale filter applied." << endl;
}
Filter* Grayscale::clone() const {
    return new Grayscale(*this);
}