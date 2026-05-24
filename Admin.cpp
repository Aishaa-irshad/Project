
#include "Admin.h"
//constructors
Admin::Admin(): User("", "", "", "", "", ""){}
Admin::Admin(const string& name):User("","", name, "", "", ""){}
//destructors
Admin::~Admin(){}
string Admin::getRole() const{
    return "Admin";
}