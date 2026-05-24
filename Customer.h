#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
using namespace std;

class Customer: public User{
private:   
    bool blocked;
    int completedSessions;
public:
//constructor
    Customer();
    Customer(const std::string& userCnic,
             const std::string& userPassword,
             const std::string& userFullName,
             const std::string& userGender,
             const std::string& userPhone,
             const std::string& userCity,
             bool isBlocked = false);
    virtual ~Customer();
    bool isBlockedAccount() const;
    void setBlocked(bool value);

    int getCompletedSessions() const;
    void setCompletedSessions(int value);
    void incrementCOmpletedSessions();

    virtual string getRole() const;
};
#endif