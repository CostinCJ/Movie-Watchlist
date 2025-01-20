#include "domain.h"
using namespace std;

// Constructor with parameters for Movie class
Movie::Movie(const string& title, const string& genre, int yearOfRelease, int numberOfLikes, const URL& trailer)
    : title(title), genre(genre), yearOfRelease(yearOfRelease), numberOfLikes(numberOfLikes), trailer(trailer) {}

// Default constructor
Movie::Movie() : title(""), genre(""), yearOfRelease(0), numberOfLikes(0), trailer("") {} 

// Destructor for Movie class
Movie::~Movie() {}

string Movie::getTitle() const
{
    return title;
}

void Movie::setTitle(const string& title)
{
    this->title = title;
}

string Movie::getGenre() const
{
    return genre;
}

void Movie::setGenre(const string& genre)
{
    this->genre = genre;
}

int Movie::getYearOfRelease() const
{
    return yearOfRelease;
}

void Movie::setYearOfRelease(int yearOfRelease)
{
    this->yearOfRelease = yearOfRelease;
}

int Movie::getNumberOfLikes() const
{
    return numberOfLikes;
}

void Movie::setNumberOfLikes(int numberOfLikes)
{
    this->numberOfLikes = numberOfLikes;
}

URL Movie::getTrailer() const  
{
    return trailer;
}

void Movie::setTrailer(const URL& trailer)
{
    this->trailer = trailer;
}

bool Movie::operator==(const Movie& other) const {
    return title == other.title && genre == other.genre && yearOfRelease == other.yearOfRelease && numberOfLikes == other.numberOfLikes && trailer == other.trailer;
}

void Movie::increaseLikes() {
    numberOfLikes++;
}

std::ostream& operator<<(std::ostream& os, const Movie& movie) {
    os << movie.title << "\n" << movie.genre << "\n" << movie.yearOfRelease << "\n" << movie.numberOfLikes << "\n" << movie.trailer << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Movie& movie) {
    std::getline(is, movie.title);
    std::getline(is, movie.genre);
    is >> movie.yearOfRelease;
    is >> movie.numberOfLikes;
    is.ignore();  
    std::getline(is, movie.trailer);
    return is;
}
