#ifndef FILTER_H
#define FILTER_H


#include <string>
using namespace std;
class Image;
class Filter {
private:
    string filterId;
    string filterName;
    string category;
public:
    Filter(const string& id, const string& name, const string& filterCategory);
    virtual ~Filter();

    const string& getId() const;
    const string& getName() const;
    const string& getCategory() const;

    virtual void apply(Image& image) const = 0;
    virtual Filter* clone() const =0;
};
#endif