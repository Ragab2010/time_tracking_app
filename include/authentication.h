#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>

class User {
public:
    User(const std::string username, const std::string password);
    bool authenticate();
private:
    std::string username;
    std::string password;
};

#endif
