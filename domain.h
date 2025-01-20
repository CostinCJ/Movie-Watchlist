#pragma once
#include "libraries.h"
using namespace std;

typedef string URL;

class Movie {
public:
    Movie();
    Movie(const string& title, const string& genre, int yearOfRelease, int numberOfLikes, const URL& trailer);
    ~Movie();

    string getTitle() const;
    void setTitle(const string& title);

    string getGenre() const;
    void setGenre(const string& genre);

    int getYearOfRelease() const;
    void setYearOfRelease(int yearOfRelease);

    int getNumberOfLikes() const;
    void setNumberOfLikes(int numberOfLikes);

    URL getTrailer() const;
    void setTrailer(const URL& trailer);

    void increaseLikes();

    bool operator==(const Movie& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
    friend std::istream& operator>>(std::istream& is, Movie& movie);

private:
    string title;
    string genre;
    int yearOfRelease;
    int numberOfLikes;
    URL trailer;
};

