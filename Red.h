#ifndef RED_H
#define RED_H

#include <iostream>
#include <string>
#include "Filter.h"

using namespace std;

class Red:public Filter{
public:
    Red();
    virtual ~Red();

    virtual void apply(Image& image)const;
    virtual Filter* clone() const;
};
#endif