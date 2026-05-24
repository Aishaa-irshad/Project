#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H
#include "Filter.h"

#include <iostream>
using namespace std;

class Brightness : public Filter{
private: 
    int delta; //brightness adjustment value
public:
//constructor
    Brightness(int amount =30);
    virtual ~Brightness();
//setter
    void setDelta(int amount);
//getter
    int getDelta() const;
//apply brightness filter
    virtual void apply(Image& image) const;
    virtual Filter* clone() const;
};
#endif