#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "domain.h"
#include "MovieValidator.h"
#include "exceptions.h"
#include "FileWriter.h"

class MovieDatabase {
private:
    std::vector<Movie> movies;
    std::vector<Movie> watchlist;
    int currentMovie;
public:
    MovieDatabase();
    ~MovieDatabase();
    void addMovie(const Movie& movie);
    void removeMovie(const string& title, const string& genre);
    void updateMovie(const string& title, const string& genre, const Movie& newMovie);
    Movie& getMovie(int index);
    size_t getMovieCount() const;
    bool movieExists(const Movie& movie) const;
    bool movieExistsUpdate(const string& title, const string& genre);
    Movie firstMovie(const string& genre);
    Movie nextMovie(const string& genre);
    bool isEmpty() const;
    void addToWatchlist(const Movie& movie);
    void removeFromWatchlist(const Movie& movie);
    void rateMovie(const Movie& movie);
    const std::vector<Movie> getWatchlist() const;
    const std::vector<Movie>& getMovies() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void saveWatchlistToFile(const std::string& filename, FileWriter& fileWriter) const;
};
