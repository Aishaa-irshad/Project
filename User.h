#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
using namespace std;

class User{
protected:
    string cnic;
    string password;
    string name;
    string gender;
    string phonenumber;
    string city;

public:
//constructors
    User();
    User(const string& cnic, const string& password, const string& name, const string& gender, const string& phonenumber, const string& city);
//destructor
    virtual ~User();

//getters
    const string getCnic() const;
    const string getPassword() const;
    const string getFullName() const;
    const string getGender() const;
    const string getPhone() const;
    const string getCity() const;
//setters
    void setCnic(const string& value);
    void setPassword(const string& value);
    void setFullName(const string& value);
    void setGender(const string& value);
    void setPhone(const string& value);
    void setCity(const string& value);

    virtual string getRole() const =0;
};

#endif