#ifndef INVERT_H
#define INVERT_H
#include "Filter.h"

#include <iostream>
using namespace std;

class Invert : public Filter{
public:
    Invert();
    virtual ~Invert();
//this apply invert filter
    virtual void apply(Image& image) const;
    virtual Filter* clone() const;
    
};
#endif