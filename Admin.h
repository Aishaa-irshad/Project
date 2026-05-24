#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"
using namespace std;

class Admin : public User {
public:
  Admin();
  Admin(const string &name);
  virtual ~Admin();
  virtual string getRole() const;
};
#endif
