#include "CSVWriter.h"

void CSVWriter::write(const std::vector<Movie>& movies, std::ofstream& file) const {
    for (const auto& movie : movies) {
        file << movie.getTitle() << "," << movie.getGenre() << "," << movie.getYearOfRelease() << "," << movie.getNumberOfLikes() << "," << movie.getTrailer() << "\n";
    }
}