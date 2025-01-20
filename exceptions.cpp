#include "Exceptions.h"

MovieAlreadyExistsException::MovieAlreadyExistsException(const std::string& message)
    : std::runtime_error(message) {}
