#include "Filter.h"

Filter::Filter(const std::string& id, const std::string& name, const std::string& filterCategory)
    : filterId(id), filterName(name), category(filterCategory) {
}
Filter::~Filter(){
}

const string& Filter::getId() const{
    return filterId;
}
const string& Filter::getName() const{
    return filterName;
}
const string& Filter::getCategory() const{
    return category;
}
