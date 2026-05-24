#include "Customer.h"


//constructor
Customer::Customer()
    : User("", "", "", "", "", ""), blocked(false), completedSessions(0){
}
Customer::Customer(const string& userCnic,
                   const string& userPassword,
                   const string& userFullName,
                   const string& userGender,
                   const string& userPhone,
                   const string& userCity,
                   bool isBlocked)
    : User(userCnic, userPassword, userFullName, userGender, userPhone, userCity),
      blocked(isBlocked),
      completedSessions(0) {
}
Customer::~Customer() {
}
bool Customer::isBlockedAccount() const{
    return blocked;
}

void Customer::setBlocked(bool value){
    blocked = value;
}
int Customer::getCompletedSessions() const{
    return completedSessions;
}
void Customer::setCompletedSessions(int value){
    completedSessions = value;
}
void Customer::incrementCOmpletedSessions(){
        completedSessions++;
}
string Customer::getRole() const {
    return "Customer";
}
