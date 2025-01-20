#include "UI.h"
#include "CSVWriter.h"
#include "HtmlWriter.h"
#include "FileWriterFactory.h"
#include <iostream>
#include <limits>


void UI::printMenuAdmin() {
    std::cout << "1. Add movie\n";
    std::cout << "2. Remove movie\n";
    std::cout << "3. Update movie\n";
    std::cout << "4. Show all movies\n";
    std::cout << "0. Exit to roles\n";
}

void UI::printMenuUser() {
    std::cout << "1. See Movies or add to the watchlist\n";
    std::cout << "2. Delte movie from the watchlist\n";
    std::cout << "3. See the watchlist\n";
    std::cout << "4. Open the watchlist file\n";
    std::cout << "0. Exit to roles\n";
}

void UI::chooseRole() {
    std::cout << "Please choose an application mode: \n";
    std::cout << "1. Admin\n";
    std::cout << "2. User\n";
    std::cout << "0. Exit program\n";
}

int UI::chooseStorageMethod() {
    int choice;
    std::cout << "Choose a storage method:\n";
    std::cout << "1. Memory\n";
    std::cout << "2. File\n";
    std::cin >> choice;
    return choice;
}

void UI::generateMovies() {
    try {
        Movie movie("Dune", "Sci-Fi", 2021, 123, "https://www.youtube.com/watch?v=n9xhJrPXop4");
        movieDatabase.addMovie(movie);
        Movie movie1("Dune 2", "Sci-Fi", 2024, 1244, "https://www.youtube.com/watch?v=Way9Dexny3w");
        movieDatabase.addMovie(movie1);
        Movie movie2("Interstellar", "Sci-Fi", 2014, 898, "https://www.youtube.com/watch?v=zSWdZVtXT7E");
        movieDatabase.addMovie(movie2);
        Movie movie3("Blade Runner 2049", "Sci-Fi", 2017, 764, "https://www.youtube.com/watch?v=gCcx85zbxz4");
        movieDatabase.addMovie(movie3);
        Movie movie4("The Hunger Games", "Sci-Fi", 2012, 123, "https://www.youtube.com/watch?v=PbA63a7H0bo");
        movieDatabase.addMovie(movie4);
        Movie movie5("Top Gun: Maverick", "Action", 2022, 531, "https://www.youtube.com/watch?v=giXco2jaZ_4");
        movieDatabase.addMovie(movie5);
        Movie movie6("Kingdom of the Planet of the Apes", "Action", 2024, 641, "https://www.youtube.com/watch?v=XtFI7SNtVpY");
        movieDatabase.addMovie(movie6);
        Movie movie7("Deadpool & Wolverine", "Action", 2024, 1021, "https://www.youtube.com/watch?v=uJMCNJP2ipI");
        movieDatabase.addMovie(movie7);
        Movie movie8("The Dark Knight", "Action", 2008, 812, "https://www.youtube.com/watch?v=EXeTwQWrcwY");
        movieDatabase.addMovie(movie8);
        Movie movie9("The Amazing Spider-Man", "Action", 2012, 1598, "https://www.youtube.com/watch?v=-tnxzJ0SSOw");
        movieDatabase.addMovie(movie9);
    }
    catch (const MovieAlreadyExistsException& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
}

void UI::run() {
    FileWriter* writer = nullptr;
    std::string fileType;
    int storageMethod = chooseStorageMethod();
    std::string filename;

    if (storageMethod == 2) {
        std::cout << "Please enter the file name: ";
        std::cin >> filename;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        movieDatabase.loadFromFile(filename);
    }
    else {
        generateMovies();
    }

    int optionRole;
    
    do {
        chooseRole();

        cin >> optionRole;

        if (optionRole == 1) {

            std::cout << "Admin Mode:\n";
            int option;
            do {

                printMenuAdmin();

                std::cin >> option;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 


                try {
                    if (option == 1) {
                        std::string title, genre, trailer;
                        int year, likes;
                        std::cout << "Enter title: ";
                        std::getline(std::cin, title);
                        std::cout << "Enter genre: ";
                        std::getline(std::cin, genre);
                        std::cout << "Enter year: ";
                        std::cin >> year;
                        std::cout << "Enter likes: ";
                        std::cin >> likes;
                        std::cout << "Enter trailer URL: ";
                        std::cin >> trailer;
                        Movie movie(title, genre, year, likes, trailer);
                        try {
                            movieDatabase.addMovie(movie);
                        }
                        catch (const MovieAlreadyExistsException& e) {
                            std::cout << "Error: " << e.what() << '\n';
                        }
                    }
                    else if(option == 2) {

                        std::string title, genre;
                        std::cout << "Enter title: ";
                        std::getline(std::cin, title);
                        std::cout << "Enter genre: ";
                        std::getline(std::cin, genre);
                        movieDatabase.removeMovie(title, genre);
                        
                    }
                    else if(option == 3) {

                        std::string title, genre, newTitle, newGenre, newTrailer;
                        int newYear, newLikes;
                        std::cout << "Enter title of movie to update: ";
                        std::getline(std::cin, title);
                        std::cout << "Enter genre of movie to update: ";
                        std::getline(std::cin, genre);
                        if (movieDatabase.movieExistsUpdate(title, genre)) {
                            std::cout << "Enter new title: ";
                            std::getline(std::cin, newTitle);
                            std::cout << "Enter new genre: ";
                            std::getline(std::cin, newGenre);
                            std::cout << "Enter new year: ";
                            std::cin >> newYear;
                            std::cout << "Enter new likes: ";
                            std::cin >> newLikes;
                            std::cout << "Enter new trailer: ";
                            std::cin >> newTrailer;
                            Movie newMovie(newTitle, newGenre, newYear, newLikes, newTrailer);
                            movieDatabase.updateMovie(title, genre, newMovie);
                        }
                       
                    }
                    else if(option == 4) {

                        for (const auto& movie : movieDatabase.getMovies()) {
                            std::cout << "Title: " << movie.getTitle() << " | " << "Genre: " << movie.getGenre() << " | " << "Year: " << movie.getYearOfRelease() << " | " << "Likes: " << movie.getNumberOfLikes() << " | " << "Trailer Link: " << movie.getTrailer() << "\n";
                        }
                        
                    }
                    else if(option == 0)
                        break;
                    else
                        std::cout << "Invalid option\n";
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Error: " << e.what() << '\n';
                }
                catch (const std::out_of_range& e) {
                    std::cout << "Error: " << e.what() << '\n';
                }
            } while (true);
        }
        else if (optionRole == 2) {

            std::cout << "User Mode:\n";

            int option;

         
            std::cout << "Please enter the file type (CSV or HTML) to save the watchlist: ";
            std::cin >> fileType;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            
            try {
                writer = FileWriterFactory::createWriter(fileType);
            }
            catch (const std::invalid_argument& e) {
                std::cout << "Error: " << e.what() << '\n';
                return;
            }

            do {

                printMenuUser();

                std::cin >> option;

                try {
                    if (option == 1) {

                        std::string genre;
                        std::cout << "Enter a genre (leave empty to see all movies): \n";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::getline(std::cin, genre);
                        if (genre.empty()) {
                            for (const auto& movie : movieDatabase.getMovies()) {
                                std::cout << "Title: " << movie.getTitle() << " | " << "Genre: " << movie.getGenre() << " | " << "Year: " << movie.getYearOfRelease() << " | " << "Likes: " << movie.getNumberOfLikes() << " | " << "Trailer Link: " << movie.getTrailer() << "\n";
                            }
                        }
                        else {
                            Movie movie = movieDatabase.firstMovie(genre);
                            std::cout << "Title: " << movie.getTitle() << " | " << "Genre: " << movie.getGenre() << " | " << "Year: " << movie.getYearOfRelease() << " | " << "Likes: " << movie.getNumberOfLikes() << "\n";
                            std::string command = std::string("start ") + movie.getTrailer();
                            system(command.c_str());
                            std::cout << "\n";
                            std::cout << "Do you like this movie? If you like it you can add it to the watch list and if you do not you can skip to the next one!\n";
                            std::cout << "\n";

                            while (true)
                            {
                                std::cout << "1. Add to the watchlist! \n";
                                std::cout << "2. Next Movie! \n";
                                std::cout << "0. Exit!\n";

                                int movieOption;
                                std::cin >> movieOption;

                                if (movieOption == 1) {
                                    try {
                                        movieDatabase.addToWatchlist(movie);
                                        std::cout << "Movie added to watchlist! \n";
                                    }
                                    catch (const std::invalid_argument& e) {
                                        std::cout << "Error: " << e.what() << '\n';
                                    }

                                }
                                else if (movieOption == 2) {
                                    movie = movieDatabase.nextMovie(genre);
                                    std::cout << "Title: " << movie.getTitle() << " | " << "Genre: " << movie.getGenre() << " | " << "Year: " << movie.getYearOfRelease() << " | " << "Likes: " << movie.getNumberOfLikes() << " | " << "Trailer Link: " << movie.getTrailer() << "\n";
                                    std::string command = std::string("start ") + movie.getTrailer();
                                    system(command.c_str());
                                }
                                else if (movieOption == 0) {
                                    break;
                                }
                                else {
                                    std::cout << "Invalid Option\n";
                                }
                            }

                        }
                    }
                    else if(option == 2) {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Add this line

                        std::string title, genre;
                        std::cout << "Enter title of movie to remove from watchlist: ";
                        std::getline(std::cin, title);
                        std::cout << "Enter genre of movie to remove from watchlist: ";
                        std::getline(std::cin, genre);
                        Movie movieToRemove(title, genre, 0, 0, "");
                        movieDatabase.removeFromWatchlist(movieToRemove);
                        std::cout << "Movie removed from watchlist. Did you like the movie? (1 for yes, 0 for no)\n";
                        int like;
                        std::cin >> like;
                        if (like == 1) {
                            movieDatabase.rateMovie(movieToRemove);
                            std::cout << "You liked the movie. Thank you for your feedback!\n";
                        }
                       
                    }
                    else if(option == 3) {
                        const std::vector<Movie>& watchlist = movieDatabase.getWatchlist();
                        for (const auto& movie : movieDatabase.getWatchlist()) {
                            std::cout << "Title: " << movie.getTitle() << " | " << "Genre: " << movie.getGenre() << " | " << "Year: " << movie.getYearOfRelease() << " | " << "Likes: " << movie.getNumberOfLikes() << " | " << "Trailer Link: " << movie.getTrailer() << "\n";
                        }
                        
                    }
                    else if (option == 4) {
                        std::string command;
                        if (fileType == "CSV") {
                            command = "notepad.exe watchlist.csv";
                        }
                        else if (fileType == "HTML") {
                            command = "start watchlist.html";
                        }
                        system(command.c_str());
                    }
                    else if(option == 0)
                        break;
                    else
                        std::cout << "Invalid option\n";
                    
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Error: " << e.what() << '\n';
                }
                catch (const std::out_of_range& e) {
                    std::cout << "Error: " << e.what() << '\n';
                }
            } while (true);
        }
    } while (optionRole != 0);

    std::ofstream outFile("watchlist." + fileType);
    if (!outFile) {
        std::cout << "Error opening file for writing\n";
        delete writer;
        return;
    }

    writer->write(movieDatabase.getWatchlist(), outFile);

    outFile.close();

    if (storageMethod == 2) {
        movieDatabase.saveToFile(filename);
    }
} 