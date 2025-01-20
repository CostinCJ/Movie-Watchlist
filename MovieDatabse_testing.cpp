#include "MovieDatabase.h"
#include <cassert>
#include <vector>
#include "MovieDatabase_testing.h"

void testMovieDatabase() {
    MovieDatabase db;

    assert(db.isEmpty() == true);

    Movie movie1("Title1", "Genre1", 2000, 100, "Trailer1");
    db.addMovie(movie1);
    assert(db.isEmpty() == false);

    assert(db.movieExists(movie1) == true);

    assert(db.getMovieCount() == 1);

    Movie retrievedMovie = db.getMovie(0);
    assert(retrievedMovie.getTitle() == "Title1");
    assert(retrievedMovie.getGenre() == "Genre1");

    db.removeMovie("Title1", "Genre1");
    assert(db.isEmpty() == true);

    Movie movie2("Title2", "Genre2", 2001, 200, "Trailer2");
    db.addMovie(movie1);
    db.updateMovie("Title1", "Genre1", movie2);
    retrievedMovie = db.getMovie(0);
    assert(retrievedMovie.getTitle() == "Title2");
    assert(retrievedMovie.getGenre() == "Genre2");

    Movie movie3("Genre2", "Genre2", 2002, 300, "Trailer3");
    db.addMovie(movie3);
    Movie firstMovie = db.firstMovie("Genre2");
    assert(firstMovie.getTitle() == "Title2");
    Movie nextMovie = db.nextMovie("Genre2");
    assert(nextMovie.getTitle() == "Genre2");


    db.addToWatchlist(movie2);
    std::vector<Movie> watchlist = db.getWatchlist();
    assert(watchlist.size() == 1);
    assert(watchlist[0].getTitle() == "Title2");


    db.removeFromWatchlist(movie2);
    watchlist = db.getWatchlist();
    assert(watchlist.size() == 0);


    db.rateMovie(movie2);
    retrievedMovie = db.getMovie(0);
    assert(retrievedMovie.getNumberOfLikes() == 201);

    MovieDatabase mdb;

    Movie m1("Title1", "Genre1", 2000, 100, "Link1");
    Movie m2("Title2", "Genre2", 2001, 200, "Link2");
    Movie m3("Title3", "Genre3", 2002, 300, "Link3");

    mdb.addMovie(m1);
    mdb.addMovie(m2);


    try {
        assert(mdb.movieExistsUpdate(m1.getTitle(), m1.getGenre()) == true);
        assert(mdb.movieExistsUpdate(m2.getTitle(), m2.getGenre()) == true);
    }
    catch (const std::invalid_argument&) {
        assert(false);
    }

    try {
        mdb.movieExistsUpdate(m3.getTitle(), m3.getGenre());
        assert(false);
    }
    catch (const std::invalid_argument&) {
        assert(true);
    }

    MovieDatabase mdb1;

    Movie m12("Title1", "Genre1", 2000, 100, "Link1");
    Movie m23("Title2", "Genre1", 2001, 200, "Link2");
    Movie m34("Title3", "Genre2", 2002, 300, "Link3");
    mdb1.addMovie(m12);
    mdb1.addMovie(m23);
    mdb1.addMovie(m34);


    assert(mdb1.nextMovie("Genre1") == m12);
    assert(mdb1.nextMovie("Genre1") == m23);
    assert(mdb1.nextMovie("Genre1") == m12); 

    assert(mdb1.nextMovie("Genre2") == m34);

    try {
        Movie invalidMovie("", "", -1, -1, "");
        db.addMovie(invalidMovie);
        assert(false);
    }
    catch (const std::invalid_argument&) {
        assert(true);
    }

    try {
        db.addMovie(movie1);
        db.addMovie(movie1);
        assert(false);
    }
    catch (const std::invalid_argument&) {
        assert(true);
    }

    try {
        db.removeMovie("Nonexistent title", "Nonexistent genre");
        assert(false);
    }
    catch (const std::invalid_argument&) {
        assert(true);
    }

    try {
        db.updateMovie("Nonexistent title", "Nonexistent genre", movie1);
        assert(false);
    }
    catch (const std::invalid_argument&) {
        assert(true);
    }

    try {
        db.getMovie(-1);
        assert(false);
    }
    catch (const std::out_of_range&) {
        assert(true);
    }

    try {
        db.firstMovie("Nonexistent genre");
        assert(false);
    }
    catch (const std::invalid_argument&) {
        assert(true);
    }

    try {
        Movie nonexistentMovie("Nonexistent title", "Nonexistent genre", 2000, 100, "Nonexistent trailer");
        db.addToWatchlist(nonexistentMovie);
        assert(false);
    }
    catch (const std::invalid_argument&) {
        assert(true);
    }

    try {
        db.addToWatchlist(movie1);
        db.addToWatchlist(movie1);
        assert(false);
    }
    catch (const std::invalid_argument&) {
        assert(true);
    }

    try {
        Movie nonexistentMovie("Nonexistent title", "Nonexistent genre", 2000, 100, "Nonexistent trailer");
        db.removeFromWatchlist(nonexistentMovie);
        assert(false);
    }
    catch (const std::invalid_argument&) {
        assert(true);
    }

    try {
        Movie nonexistentMovie("Nonexistent title", "Nonexistent genre", 2000, 100, "Nonexistent trailer");
        db.rateMovie(nonexistentMovie);
        assert(false);
    }
    catch (const std::invalid_argument&) {
        assert(true);
    }

}

