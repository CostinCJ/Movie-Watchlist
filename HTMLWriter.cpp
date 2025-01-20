#include "HTMLWriter.h"

void HTMLWriter::write(const std::vector<Movie>& movies, std::ofstream& file) const {
    file << "<!DOCTYPE html>\n";
    file << "<html>\n";
    file << "<head>\n";
    file << "<title>Movie Watchlist</title>\n";
    file << "</head>\n";
    file << "<body>\n";
    file << "<table border=\"1\">\n";
    file << "<tr><td>Title</td><td>Genre</td><td>Year</td><td>Likes</td><td>Trailer</td></tr>\n";
    for (const auto& movie : movies) {
        file << "<tr><td>" << movie.getTitle() << "</td><td>" << movie.getGenre() << "</td><td>" << movie.getYearOfRelease() << "</td><td>" << movie.getNumberOfLikes() << "</td><td><a href=\"" << movie.getTrailer() << "\">Link</a></td></tr>\n";
    }
    file << "</table>\n";
    file << "</body>\n";
    file << "</html>\n";
}
