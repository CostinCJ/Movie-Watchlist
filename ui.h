#pragma once
#include "MovieDatabase.h"
#include "FileWriter.h"

class UI {
private:
    MovieDatabase movieDatabase;
public:
    void printMenuAdmin();
    void printMenuUser();
    void chooseRole();
    void generateMovies();
    void run();
    int chooseStorageMethod();
};
