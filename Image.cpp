#include "Image.h"
#include "ImageFile.h"
#include <iostream>
#include <cstring>
using namespace std;
void Image::clearGrid() {
    if (pixels != nullptr) {
        for (int i = 0; i < height; i++) {
            delete[] pixels[i];
        }
        delete[] pixels;
        pixels = nullptr;
    }
    width = 0;
    height = 0;
}
 
void Image::allocateGrid(int w, int h) {
    pixels = new Pixel*[h];
    for (int i = 0; i < h; i++) {
        pixels[i] = new Pixel[w];
    }
    width = w;
    height = h;
}
 
// Constructor 
Image::Image() : pixels(nullptr), width(0), height(0) {}
Image::Image(int w, int h) : pixels(nullptr), width(0), height(0) {
    allocateGrid(w, h);
}
Image::Image(const Image& other) : pixels(nullptr), width(0), height(0) {
    if (!other.isEmpty()) {
        allocateGrid(other.width, other.height);
        
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                pixels[row][col] = other.pixels[row][col];
            }
        }
    }
}
 
// Destructor
Image::~Image() {
    clearGrid();
}
 
// Assignment operator - deep copy
Image& Image::operator=(const Image& other) {
    if (this != &other) {
        clearGrid();
        
        if (!other.isEmpty()) {
            allocateGrid(other.width, other.height);
            
            for (int row = 0; row < height; row++) {
                for (int col = 0; col < width; col++) {
                    pixels[row][col] = other.pixels[row][col];
                }
            }
        }
    }
    return *this;
}
 
// Resize image - clears old data and creates new
bool Image::resize(int w, int h) {
    if (w <= 0 || h <= 0) {
        cout << "Error: Invalid dimensions " << w << "x" << h << endl;
        return false;
    }
    
    clearGrid();
    allocateGrid(w, h);
    return true;
}
 
// Get pixel reference (for modification)
Pixel& Image::at(int row, int col) {
    if (row < 0 || row >= height || col < 0 || col >= width) {
        cout << "Error: Pixel access out of bounds (" << row << "," << col << ")" << endl;
        cout << "Image size: " << width << "x" << height << endl;
        // Return first pixel as fallback
        static Pixel fallback(0, 0, 0);
        return fallback;
    }
    return pixels[row][col];
}
 
// Get pixel (const version)
const Pixel& Image::at(int row, int col) const {
    if (row < 0 || row >= height || col < 0 || col >= width) {
        cout << "Error: Pixel access out of bounds (" << row << "," << col << ")" << endl;
        cout << "Image size: " << width << "x" << height << endl;
        // Return first pixel as fallback
        static Pixel fallback(0, 0, 0);
        return fallback;
    }
    return pixels[row][col];
}
 
// Check if image is empty
bool Image::isEmpty() const {
    return (width == 0 || height == 0 || pixels == nullptr);
}
 
// Get width
int Image::getWidth() const {
    return width;
}
 
// Get height
int Image::getHeight() const {
    return height;
}
 
// Save to file (delegates to ImageFile)
bool Image::saveToFile(const string& path) const {
    return ImageFile::saveImage(path, *this);
}
 
// Display as ASCII art (capped at 80x40 to avoid flooding the terminal)
void Image::displayASCII() const {
    if (isEmpty()) {
        cout << "Image is empty!" << endl;
        return;
    }
 
    const int MAX_COLS = 80;
    const int MAX_ROWS = 40;
    int previewW = (width  < MAX_COLS) ? width  : MAX_COLS;
    int previewH = (height < MAX_ROWS) ? height : MAX_ROWS;

    cout << "========== ASCII PREVIEW ==========" << endl;
    cout << "Image size: " << width << "x" << height << " pixels" << endl;
    if (width > MAX_COLS || height > MAX_ROWS)
        cout << "(showing " << previewW << "x" << previewH << " preview of full image)" << endl;

    for (int row = 0; row < previewH; row++) {
        for (int col = 0; col < previewW; col++) {
            cout << pixels[row][col];
        }
        cout << "\n";
    }

    cout << "===================================" << endl << endl;
}
 
// Convert image to RGB buffer (for external processing)
bool Image::setFromRGBBuffer(const unsigned char* data, int w, int h) {
    if (data == nullptr || w <= 0 || h <= 0) {
        cout << "Error: Invalid buffer or dimensions" << endl;
        return false;
    }
    
    // Resize image to match buffer dimensions
    if (!resize(w, h)) {
        return false;
    }
    
    // Copy RGB data into pixels
    int index = 0;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            unsigned char r = data[index++];
            unsigned char g = data[index++];
            unsigned char b = data[index++];
            
            pixels[row][col] = Pixel(r, g, b);
        }
    }
    
    return true;
}
 
// Convert image to RGB buffer (for external saving)
unsigned char* Image::toRGBBuffer() const {
    if (isEmpty()) {
        cout << "Error: Cannot convert empty image to buffer" << endl;
        return nullptr;
    }
    
    // Allocate buffer: width * height * 3 (RGB)
    int bufferSize = width * height * 3;
    unsigned char* buffer = new unsigned char[bufferSize];
    
    // Copy pixel data to buffer
    int index = 0;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            buffer[index++] = (unsigned char)pixels[row][col].getRed();
            buffer[index++] = (unsigned char)pixels[row][col].getGreen();
            buffer[index++] = (unsigned char)pixels[row][col].getBlue();
        }
    }
    
    return buffer;
}
 