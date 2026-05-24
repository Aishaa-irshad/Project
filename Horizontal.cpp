#include "Horizontal.h"
#include "Image.h"

Horizontal::Horizontal() : Filter("09", "Flip Horizontal", "Geometric") {
}

Horizontal::~Horizontal() {
}

void Horizontal::apply(Image& image) const {
    for (int row = 0; row < image.getHeight(); row++) {
        for (int col = 0; col < image.getWidth() / 2; col++) {
            Pixel temp = image.at(row, col);
            image.at(row, col) = image.at(row, image.getWidth() - 1 - col);
            image.at(row, image.getWidth() - 1 - col) = temp;
        }
    }
}

Filter* Horizontal::clone() const {
    return new Horizontal(*this);
}
