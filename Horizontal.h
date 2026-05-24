#ifndef HORIZONTAL_H
#define HORIZONTAL_H
#include "Filter.h"

class Horizontal : public Filter {
public:
    Horizontal();
    virtual ~Horizontal();

    virtual void apply(Image& image) const;
    virtual Filter* clone() const;
};
#endif