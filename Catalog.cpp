#include "Catalog.h"
#include <fstream>
#include <sstream>

static vector<string> splitCatalogLine(const string& line){
    vector<string> parts;
    stringstream stream(line);
    string token;
    while (getline(stream, token, '|')){
            parts.push_back(token);
        }
        return parts;
}

vector<CatalogManager::CatalogRecord> CatalogManager::loadCatalog(const string& path) const{
    vector<CatalogRecord> catalog;
    ifstream file(path.c_str());
    
    if (!file.is_open()) {
        return catalog;
    }

    string line;
    while (std::getline(file, line)){
        if (line.empty()) {
            continue;
        }
    vector<string> parts = splitCatalogLine(line);
        if (parts.size()<4){
            continue;
        }
        CatalogRecord record;
        record.filterId = parts[0];
        record.filterName = parts[1];
        record.category = parts[2];
        record.enabled = (parts[3] == "1");
        catalog.push_back(record);
    }
    return catalog;
}

bool CatalogManager::saveCatalog(const vector<CatalogRecord>& catalog, const string& path)const{
    ofstream file(path.c_str(),ios::out);
    if (!file.is_open()) {
        return false;
    }

    for (int i = 0; i <catalog.size(); i++) {
        file << catalog[i].filterId << '|'
             << catalog[i].filterName << '|'
             << catalog[i].category << '|'
             << (catalog[i].enabled ? 1 : 0) << '\n';
            }   
    
    file.close();
    return true;
}

bool CatalogManager::isFilterEnabled(const string& path, const string& filterId){
    vector<CatalogRecord> catalog = loadCatalog(path);

    for(int i=0; i< catalog.size(); i++){
        if(catalog[i].filterId == filterId){
            catalog[i].enabled = !catalog[i].enabled;
            return saveCatalog(catalog, path);
        }
    }
    return false;
}

// void CatalogManager::setFilterStatus(int filterId, bool enabled) {
//     if (filterId >= 1 && filterId <= 10) {
//         filterEnabled[filterId - 1] = enabled;
//         cout << "Filter " << filterNames[filterId - 1] << " is now "
//              << (enabled ? "ENABLED" : "DISABLED") << endl;
//         saveCatalog();
//     }
// }

// void CatalogManager::displayAllFilters() {
//     cout << "\n===== FILTER CATALOG =====" << endl;
//     cout << "ID | Filter Name | Status" << endl;
//     cout << "---|-------------|--------" << endl;
    
//     for (int i = 0; i < 10; i++) {
//         cout << (i + 1) << " | " << filterNames[i] << " | "
//              << (filterEnabled[i] ? "ENABLED" : "DISABLED") << endl;
//     }
// }

// string CatalogManager::getFilterStatus(int filterId) {
//     if (filterId >= 1 && filterId <= 10) {
//         return filterEnabled[filterId - 1] ? "ENABLED" : "DISABLED";
//     }
//     return "UNKNOWN";
// }