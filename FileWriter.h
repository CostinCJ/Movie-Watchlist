#pragma once
#include <vector>
#include <fstream>
#include "domain.h"

class FileWriter {
public:
    virtual ~FileWriter() {}
    virtual void write(const std::vector<Movie>& movies, std::ofstream& file) const = 0;
};
