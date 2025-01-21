# Movie-Watchlist
This project is a C++ application for managing a movie database, featuring a command-line interface, file handling for data persistence, and comprehensive testing to ensure robust functionality. It provides a system for managing movies and user watchlists while showcasing key programming concepts such as object-oriented design, file handling, and testing. Below is a detailed description of its components and features.

### **Key Features**

#### **Command-Line Interface**  
The application is operated through a user-friendly CLI implemented in the `UI` class. Users can add, remove, update, and list movies, as well as manage their personal watchlist. The interface includes prompts for various operations and effectively handles user input.

#### **Data Management**  
The application manages movies and watchlists using the `MovieDatabase` class. This class provides methods for adding, removing, updating, and retrieving movies, as well as managing a user's watchlist.

#### **File Handling**  
The application supports saving and loading movie data to ensure persistence. Users can export movie data in **CSV** or **HTML** formats using specialized file writers (`CSVWriter` and `HTMLWriter`). The `FileWriterFactory` dynamically creates the appropriate file writer based on the user's desired format.

#### **Error Handling**  
Custom exceptions (e.g., `MovieAlreadyExistsException`) ensure that invalid operations (such as adding duplicate movies) are handled gracefully without crashing the program. Users are notified of errors with informative messages and prompted to correct their input.

#### **Unit Testing**  
Comprehensive testing is implemented to validate core functionalities such as adding/removing movies, updating movie details, and managing the watchlist. This ensures the correctness and reliability of the application.

#### **Object-Oriented Design**  
The program is modular, with separate classes for movies, the movie database, file writers, and the user interface. This structure promotes code reusability, scalability, and maintainability.

### **How It Works**

#### **Initialization**  
The program starts by running unit tests to ensure all core functionalities work correctly. After successful testing, it initializes the `UI` class and starts the command-line interface.

#### **Data Operations**  
Users can perform various operations such as adding/removing movies, updating movie details, listing all movies in the database, and managing their watchlist. The `UI` class interacts with the `MovieDatabase` class to handle these data manipulations.

#### **File Handling**  
Users can save movie data to files or load it from previously saved files for continuity between sessions. Exporting data is supported in CSV or HTML formats using file writers created by the `FileWriterFactory`.

#### **Error Handling**  
The application catches exceptions during invalid operations (e.g., duplicate entries or invalid inputs). Informative error messages are displayed to guide users in correcting their actions while ensuring smooth program execution.

#### **Testing**  
Unit tests cover all major functionalities such as adding/removing movies, updating details, managing watchlists, and exporting data. This ensures that the application behaves as expected across different use cases.

### **This project demonstrates key programming concepts such as:**

- Modular design using object-oriented programming principles.
- Flexible data storage options with different file writers.
- Error handling with custom exceptions for robust applications.
- Writing unit tests for validating functionality and ensuring code reliability.
5. Integrate an external API (e.g., IMDb) to fetch movie details automatically.

This project combines practical software development concepts with C++ programming techniques to create a functional movie database management system that is both robust and extensible!

