#ifndef GREEN_H
#define GREEN_H

#include "Filter.h"
using namespace std;

class Green:public Filter{
public:
    Green();
    virtual ~Green();
    
    virtual void apply(Image& image) const;
    virtual Filter* clone() const;
};
#endif