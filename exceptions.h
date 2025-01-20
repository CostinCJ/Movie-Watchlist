#pragma once
#include <stdexcept>
#include <string>

class MovieAlreadyExistsException : public std::runtime_error {
public:
    MovieAlreadyExistsException(const std::string& message);
};
