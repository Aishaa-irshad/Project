#ifndef VERTICAL_H
#define VERTICAL_H
#include "Filter.h"

class Vertical : public Filter {
public:
    Vertical();
    virtual ~Vertical();
    
    virtual void apply(Image& image) const;
    virtual Filter* clone() const;
};
#endif