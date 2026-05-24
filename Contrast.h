#ifndef CONTRAST_H
#define CONTRAST_H
#include "Filter.h"

using namespace std;

class Contrast : public Filter{
public: 
    Contrast();
    virtual ~Contrast();

    virtual void apply(Image& image)const;
    virtual Filter* clone() const;
};
#endif