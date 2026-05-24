#include "FilterSession.h"
#include "Image.h"
#include <sstream>

FilterSession::FilterSession() {
}

void FilterSession::copyFrom(const FilterSession& other) {
    for (int i = 0; i < other.filters.size(); i++) {
        filters.push_back(other.filters[i]->clone());
    }
}

FilterSession::FilterSession(const FilterSession& other) {
    copyFrom(other);
}

FilterSession& FilterSession::operator=(const FilterSession& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

FilterSession::~FilterSession() {
    clear();
}

FilterSession& FilterSession::addFilter(const Filter& filter) {
    filters.push_back(filter.clone());
    return *this;
}

void FilterSession::clear() {
    for (int i = 0; i < filters.size(); i++) {
        delete filters[i];
    }
    filters.clear();
}

void FilterSession::apply(Image& image) const {
    for (int i = 0; i < filters.size(); i++) {
        filters[i]->apply(image);
    }
}

string FilterSession::getPipelineText() const {
    ostringstream out;
    if (filters.empty()) {
        out << "(empty)";
        return out.str();
    }

    for (int i = 0; i < filters.size(); i++) {
        out << filters[i]->getName();
        if (i + 1 < filters.size()) {
            out << " -> ";
        }
    }

    return out.str();
}

int FilterSession::count() const {
    return (int)filters.size();
}

const vector<Filter*>& FilterSession::getFilters() const {
    return filters;
}
