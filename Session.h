#ifndef SESSION_H
#define SESSION_H

#include <vector>
#include <string>
using namespace std;

class Session {
public:
    struct SessionRecord {
        string cnic;
        string timestamp;
        string filtersApplied;
        string outputFile;
    };

    bool appendSession(const SessionRecord& record, const string& path) const;
    vector<SessionRecord> loadAll(const string& path) const;
    vector<SessionRecord> loadForCnic(const string& path, const string& cnic) const;
};
#endif