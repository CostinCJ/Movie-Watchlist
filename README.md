# Movie-Watchlist
This project is a C++ application for managing a movie database, featuring a command-line interface, file handling for data persistence, and comprehensive testing to ensure robust functionality. It provides a system for managing movies and user watchlists, showcasing key programming concepts such as object-oriented design, file handling, and testing. Below is a detailed description of its components and features.
Key Features
Command-Line Interface: The application is operated through a user-friendly CLI implemented in the UI class. Users can add, remove, update, and list movies, as well as manage a watchlist. The interface includes prompts for various operations and handles user input effectively.
Data Management: The application manages movies and watchlists using the MovieDatabase class. This class provides methods for adding, removing, updating, and retrieving movies, as well as managing a user's watchlist.
File Handling: The application supports saving and loading movie data to and from files. It includes different file writers (CSVWriter and HTMLWriter) to export movie data in CSV and HTML formats, respectively. The FileWriterFactory class is used to create the appropriate file writer based on the desired format.
Error Handling: Custom exceptions (e.g., MovieAlreadyExistsException) ensure that invalid operations (such as adding a movie that already exists) are handled gracefully without crashing the program. Users are notified of errors and prompted to correct their input.
Unit Testing: Comprehensive testing is implemented to validate core functionalities such as adding/removing movies, updating movie details, and managing the watchlist. This ensures the correctness and reliability of the application.
Object-Oriented Design: The program is modular, with separate classes for movies, the movie database, file writers, and the user interface. This structure promotes code reusability and scalability.
How It Works
Initialization: The program starts by running tests to ensure the core functionalities are working correctly. It then initializes the UI class and starts the command-line interface.
Data Operations: Users can perform various operations such as adding/removing movies, updating movie details, listing all movies, and managing their watchlist. The UI class provides methods for each of these operations and interacts with the MovieDatabase class to perform the actual data manipulations.
File Handling: Users can export the movie data to CSV or HTML files using the appropriate file writer. The FileWriterFactory class is used to create the file writer based on the user's choice.
Error Handling: The application catches and handles exceptions, providing informative error messages to the user and ensuring the program continues to run smoothly.
Testing: Unit tests are written to cover all major functionalities, ensuring that the application behaves as expected under different scenarios.
This project demonstrates key programming concepts such as:
•	Modular design using object-oriented programming principles.
•	Flexible data storage options with different file writers.
•	Error handling with custom exceptions for robust applications.
•	Writing unit tests for validating functionality and ensuring code reliability.

