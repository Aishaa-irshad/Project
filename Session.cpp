#include "Session.h"
#include <fstream>
#include <sstream>

static vector<string> splitSessionLine(const string& line) {
    vector<std::string> parts;
    stringstream stream(line);
    string token;
    while (getline(stream, token, '|')) {
        parts.push_back(token);
    }
    return parts;
}

bool Session::appendSession(const SessionRecord& record, const string& path) const {
    ofstream file(path.c_str(),ios::app);
    if (!file.is_open()) {
        return false;
    }
    file << record.cnic << '|'
         << record.timestamp << '|'
         << record.filtersApplied << '|'
         << record.outputFile << '\n';

    return true;
}

vector<Session::SessionRecord> Session::loadAll(const string& path) const {
    vector<SessionRecord> records;
    ifstream file(path.c_str());

    if (!file.is_open()) {
        return records;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        vector<string> parts = splitSessionLine(line);
        if (parts.size() < 4) {
            continue;
        }

        SessionRecord record;
        record.cnic = parts[0];
        record.timestamp = parts[1];
        record.filtersApplied = parts[2];
        record.outputFile = parts[3];
        records.push_back(record);
    }

    return records;
}

vector<Session::SessionRecord> Session::loadForCnic(const string& path, const string& cnic) const {
    vector<SessionRecord> result;
    vector<SessionRecord> all = loadAll(path);

    for (int i = 0; i < all.size(); i++) {
        if (all[i].cnic == cnic) {
            result.push_back(all[i]);
        }
    }

    return result;
}
