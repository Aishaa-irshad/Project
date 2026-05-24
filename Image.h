#ifndef IMAGE_H
#define IMAGE_H
#include "Pixel.h"
#include <string>
using namespace std;

class Image{
private:
    Pixel** pixels;
    int width;
    int height;

    void clearGrid();
    void allocateGrid(int w, int h);
public:
//constructors/destructor
    Image();
    Image(int w, int h);
    Image(const Image& other);
    ~Image();

//opr
    Image& operator=(const Image& other);
    bool resize(int w, int h);
//getting pixel 
    Pixel& at(int row, int col);
    const Pixel& at(int row, int col) const;

    bool isEmpty() const;
//getters
    int getWidth() const;
    int getHeight() const;

    bool saveToFile(const string& path) const;
    void displayASCII() const;
    bool setFromRGBBuffer(const unsigned char* data, int w, int h);
    unsigned char* toRGBBuffer() const;


};

#endif