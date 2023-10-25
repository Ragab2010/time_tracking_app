#include "authentication.h"

User::User(const std::string username, const std::string password)
    : username(std::move(username)), password(std::move(password)) {}

bool User::authenticate() {
    // Simplified authentication logic
    return (username == "john_doe" && password == "password");
}
