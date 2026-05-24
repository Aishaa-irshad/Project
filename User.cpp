#include "User.h"

//constructor
User::User(){
}
User::User(const string& cnic, const string& password, const string& name, const string& gender, const string& phonenumber, const string& city){
    this->cnic = cnic;
    this->password = password;
    this->name = name;
    this->gender = gender;
    this->phonenumber = phonenumber;
    this->city = city;
}
User::~User(){
}

const string User::getCnic() const { 
    return cnic; 
}
const string User::getPassword() const { 
    return password; 
}
const string User::getFullName() const {
     return name; 
    }
const string User::getGender() const { 
    return gender;
 }
const string User::getPhone() const { 
    return phonenumber;
 }
const string User::getCity() const {
     return city; 
    }

void User::setCnic(const std::string& value) { 
    cnic = value; 
}
void User::setPassword(const std::string& value) { 
    password = value; 
}
void User::setFullName(const std::string& value) { 
    name = value;
 }
void User::setGender(const std::string& value) {
     gender = value; 
    }
void User::setPhone(const std::string& value) {
     phonenumber = value; 
    }
void User::setCity(const std::string& value) {
     city = value; 
    }
