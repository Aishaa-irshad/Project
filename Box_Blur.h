#ifndef BOX_BLUR_H
#define BOX_BLUR_H

#include "Filter.h"
using namespace std;
class Box_Blur : public Filter{
public:
    Box_Blur();
    virtual ~Box_Blur();

    virtual void apply(Image& image) const;
    virtual Filter* clone() const;
};
#endif