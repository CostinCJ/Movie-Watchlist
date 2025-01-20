#include "UI.h"
#include "domain_testing.h"
#include "MovieDatabase_testing.h"

void runTests() {
    testMovie();
    testMovieDatabase();
}

int main() {
    runTests();

    UI ui;
    ui.run();

    return 0;
}
