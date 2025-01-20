#pragma once
#include "CSVWriter.h"
#include "HTMLWriter.h"

class FileWriterFactory {
public:
    static FileWriter* createWriter(const std::string& type) {
        if (type == "CSV") {
            return new CSVWriter();
        }
        else if (type == "HTML") {
            return new HTMLWriter();
        }
        else {
            throw std::invalid_argument("Invalid file type");
        }
    }
};
