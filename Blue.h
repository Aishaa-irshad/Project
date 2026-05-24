#ifndef BLUE_H
#define BLUE_H

#include "Filter.h"
using namespace std;

class Blue:public Filter{
public:
    Blue();
    virtual ~Blue();

    virtual void apply(Image& image) const;
    virtual Filter* clone() const;
};
#endif