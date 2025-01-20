#include "MovieDatabase.h"
#include <stdexcept>

MovieDatabase::MovieDatabase() : currentMovie(0) {
    // Constructor for MovieDatabase class
}

MovieDatabase::~MovieDatabase() {
    // Destructor for MovieDataabase class
}

bool MovieDatabase::movieExists(const Movie& movie) const {
    auto it = std::find_if(movies.begin(), movies.end(), [&movie](const Movie& m) {
        return m.getTitle() == movie.getTitle() && m.getGenre() == movie.getGenre();
    });
    return it != movies.end();
}


bool MovieDatabase::movieExistsUpdate(const string& title, const string& genre) {
    auto it = std::find_if(movies.begin(), movies.end(), [&title, &genre](const Movie& m) {
        return m.getTitle() == title && m.getGenre() == genre;
        });
    if (it == movies.end()) {
        throw std::invalid_argument("Movie doesn't exist");
    }
    return true;
}


void MovieDatabase::addMovie(const Movie& movie) {
    // Adds a movie to the database
    MovieValidator validator;
    validator.validate(movie);
    if (movieExists(movie)) {
        throw std::invalid_argument("Movie already exists");
    }
    movies.push_back(movie);
}

void MovieDatabase::removeMovie(const string& title, const string& genre) {
    auto it = std::remove_if(movies.begin(), movies.end(), [&title, &genre](const Movie& m) {
        return m.getTitle() == title && m.getGenre() == genre;
    });
    if (it != movies.end()) {
        movies.erase(it, movies.end());
    }
    else {
        throw std::invalid_argument("Movie not found");
    }
}

void MovieDatabase::updateMovie(const string& title, const string& genre, const Movie& newMovie) {
    for (auto& m : movies) {
        if (m.getTitle() == title && m.getGenre() == genre) {
            m = newMovie;
            return;
        }
    }
    throw std::invalid_argument("Movie not found");
}

Movie& MovieDatabase::getMovie(int index) {
    // Gets a movie from the database at a specific index
    if (index < 0 || index >= movies.size()) {
        throw std::out_of_range("Index out of range");
    }
    return movies[index];
}

size_t MovieDatabase::getMovieCount() const {
    // Gets the number of movies
    return movies.size();
}

Movie MovieDatabase::firstMovie(const string& genre) {
    size_t start = currentMovie;
    do {
        if (movies[currentMovie].getGenre() == genre) {
            Movie movie = movies[currentMovie];
            currentMovie = (static_cast<size_t>(currentMovie) + 1) % movies.size();
            return movie;
        }
        currentMovie = (static_cast<size_t>(currentMovie) + 1) % movies.size();
    } while (currentMovie != start);

    throw std::invalid_argument("No movies of this genre");
}

Movie MovieDatabase::nextMovie(const string& genre) {
    int start = currentMovie;
    do {
        Movie movie = movies[currentMovie];
        if (movie.getGenre() == genre) {
            currentMovie = (static_cast<size_t>(currentMovie) + 1) % movies.size();
            return movie;
        }
        currentMovie = (static_cast<size_t>(currentMovie) + 1) % movies.size();
    } while (currentMovie != start);

    currentMovie = 0;

    return movies[currentMovie];
}


bool MovieDatabase::isEmpty() const {
    return movies.size() == 0;
}

void MovieDatabase::addToWatchlist(const Movie& movie) {
    // Adds a movie to the watchlist

    if (!movieExists(movie)) {
        throw std::invalid_argument("Movie does not exist in the database");
    }

    for (const auto& m : watchlist) {
        if (m.getTitle() == movie.getTitle() && m.getGenre() == movie.getGenre()) {
            throw std::invalid_argument("Movie already in watchlist");
        }
    }

    watchlist.push_back(movie);
}

void MovieDatabase::removeFromWatchlist(const Movie& movie) {
    for (auto it = watchlist.begin(); it != watchlist.end(); ++it) {
        if (it->getTitle() == movie.getTitle() && it->getGenre() == movie.getGenre()) {
            watchlist.erase(it);
            return;
        }
    }
    throw std::invalid_argument("Movie not found in watchlist");
}

void MovieDatabase::rateMovie(const Movie& movie) {
    for (auto& m : movies) {
        if (m.getTitle() == movie.getTitle() && m.getGenre() == movie.getGenre()) {
            m.increaseLikes();
            return;
        }
    }
    throw std::invalid_argument("Movie not found in database");
}

const std::vector<Movie> MovieDatabase::getWatchlist() const {
    // getter for the watchlist
    return watchlist;
}

const std::vector<Movie>& MovieDatabase::getMovies() const {
    return movies;
}

void MovieDatabase::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& movie : movies) {
        file << movie;
    }
}

void MovieDatabase::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    Movie movie;
    while (file >> movie) {
        movies.push_back(movie);
    }
}

void MovieDatabase::saveWatchlistToFile(const std::string& filename, FileWriter& fileWriter) const {
    std::ofstream file(filename);
    fileWriter.write(watchlist, file);
}

