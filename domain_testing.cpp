#include "domain_testing.h"
#include "domain.h"
#include <cassert>
#include <string>

void testMovie() {

    Movie movie("Title", "Genre", 2000, 100, "http://trailer.com");

    assert(movie.getTitle() == "Title");
    assert(movie.getGenre() == "Genre");
    assert(movie.getYearOfRelease() == 2000);
    assert(movie.getNumberOfLikes() == 100);
    assert(movie.getTrailer() == "http://trailer.com");

    movie.setTitle("New Title");
    movie.setGenre("New Genre");
    movie.setYearOfRelease(2020);
    movie.setNumberOfLikes(200);
    movie.setTrailer("http://newtrailer.com");

    assert(movie.getTitle() == "New Title");
    assert(movie.getGenre() == "New Genre");
    assert(movie.getYearOfRelease() == 2020);
    assert(movie.getNumberOfLikes() == 200);
    assert(movie.getTrailer() == "http://newtrailer.com");
    
    Movie movie_def;

    assert(movie_def.getTitle() == "");
    assert(movie_def.getGenre() == "");
    assert(movie_def.getYearOfRelease() == 0);
    assert(movie_def.getNumberOfLikes() == 0);
    assert(movie_def.getTrailer() == "");
}

