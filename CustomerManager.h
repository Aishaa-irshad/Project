#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include <string>
#include <vector>
#include "Customer.h"

using namespace std;
class CustomerManager {
public:
    struct CustomerRecord {
        string cnic;
        string password;
        string fullName;
        string gender;
        string phone;
        string city;
        bool blocked;
    };

    static bool isDigitsOnly(const string& text);
    static bool isValidCnic(const string& text);
    static bool isValidPassword(const string& text);
    static bool isValidGender(const string& text);

    vector<CustomerRecord> loadAll(const string& path) const;
    bool saveAll(const vector<CustomerRecord>& customers, const string& path) const;

    bool cnicExists(const vector<CustomerRecord>& customers, const string& cnic) const;

    bool addCustomer(const Customer& customer, const string& customersPath, const string& blockedPath) const;
};

#endif