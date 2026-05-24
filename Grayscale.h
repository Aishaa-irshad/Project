#ifndef GRAYSCALE_H
#define GRAYSCALE_H
#include "Filter.h"

#include <iostream>
using namespace std;

class Grayscale : public Filter{
public:
    Grayscale();
    virtual ~Grayscale();
//this apply grayscale filter
    virtual void apply(Image& image)const;
    virtual Filter* clone() const;
};
#endif