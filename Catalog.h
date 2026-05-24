#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include <string>
using namespace std;

class CatalogManager {
public:
    struct CatalogRecord{
        string filterId;
        string filterName;
        string category;
        bool enabled;
    };

    // Load catalog
    vector<CatalogRecord> loadCatalog(const string& path) const;

    // Save catalog
    bool saveCatalog(const vector<CatalogRecord>& catalog, const string& path) const;

    // Check if filter is enabled
    bool isFilterEnabled(const string& path, const string& filterId);
};

#endif