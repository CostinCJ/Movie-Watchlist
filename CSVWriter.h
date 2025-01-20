#pragma once
#include "FileWriter.h"

class CSVWriter : public FileWriter {
public:
    void write(const std::vector<Movie>& movies, std::ofstream& file) const override;
};