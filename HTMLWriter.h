#pragma once
#include "FileWriter.h"

class HTMLWriter : public FileWriter {
public:
    void write(const std::vector<Movie>& movies, std::ofstream& file) const override;
};
