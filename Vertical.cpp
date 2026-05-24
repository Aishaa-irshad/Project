#include "Vertical.h"
#include "Image.h"

Vertical::Vertical() : Filter("10", "Flip Vertical", "Geometric") {
}

Vertical::~Vertical() {
}

void Vertical::apply(Image& image) const {
    for (int row = 0; row < image.getHeight() / 2; row++) {
        for (int col = 0; col < image.getWidth(); col++) {
            Pixel temp = image.at(row, col);
            image.at(row, col) = image.at(image.getHeight() - 1 - row, col);
            image.at(image.getHeight() - 1 - row, col) = temp;
        }
    }
}

Filter* Vertical::clone() const {
    return new Vertical(*this);
}
