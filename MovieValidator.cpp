#include "MovieValidator.h"
#include <stdexcept>

void MovieValidator::validate(const Movie& movie) {
    if (movie.getTitle().empty()) {
        throw std::invalid_argument("Title must not be empty");
    }
    if (movie.getGenre().empty()) {
        throw std::invalid_argument("Genre must not be empty");
    }
    if (movie.getYearOfRelease() <= 0) {
        throw std::invalid_argument("Year of release must be positive");
    }
    if (movie.getNumberOfLikes() < 0) {
        throw std::invalid_argument("Number of likes must not be negative");
    }
    if (movie.getTrailer().empty()) {
        throw std::invalid_argument("Trailer must not be empty");
    }
}
