#ifndef FILTERSESSION_H
#define FILTERSESSION_H
#include <vector>
#include <string>
#include "Filter.h"

class Image;

class FilterSession {
private:
    std::vector<Filter*> filters;

    void copyFrom(const FilterSession& other);

public:
    FilterSession();
    FilterSession(const FilterSession& other);
    FilterSession& operator=(const FilterSession& other);
    ~FilterSession();

    FilterSession& addFilter(const Filter& filter);
    void clear();

    void apply(Image& image) const;
    std::string getPipelineText() const;
    int count() const;

    const std::vector<Filter*>& getFilters() const;
};
#endif
