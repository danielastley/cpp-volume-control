#include <iostream> // For input/output operations (like printing to console)
#include <limits>   // Required for numeric_limits (for robust input clearing)
#include <string>   // Required for using the string type
#include <fstream>  // Required for file stream operations (ofstream)
#include <chrono>   // Required for getting the current time
#include <ctime>    // Required for formatting time


// The main function is the entry point of the program
int main() {
    int volumeLevel; // Declare an integer variable to store the volume
    std::string volumeCategory; // Declare a string variable for the category name
    std::string outputMessage; // Declare a string variable for the display message

        // Print a simple message to the console
        std::cout << "Audio Volume Control Program Initialized." << std::endl;

    // Use a do-while loop to ensure we get valid input
    do {
        // Prompt the user for input
        std::cout << "Enter audio volume level (1-10): ";
        std::cin >> volumeLevel; // Read the integer input into volumeLevel

        // Check if the input operation failed (e.g., user entered text)
        // or if the value is outside the valid range (1-10)
        if (std::cin.fail() || volumeLevel < 1  || volumeLevel > 10) 
        {
            std::cout << "Invalid input. Please enter a number between 1 and 10." << std::endl;

            // Clear the error flag on cin
            std::cin.clear();

            // Discard the invalid input from the input buffer
            // numeric_limits<streamsize>::max() gets the maximum size of the stream
            // '\n' means discard characters until a newline is found

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            volumeLevel = 0; // Reset volumeLevel to ensure the loop continues
        } 
        else 
        {
            // Input is valid and within range, break the loop
            break;
        }

    } while (true); // Loop indefinitely until valid input is received and we 'break'

    // Categorize the valid volume level using if/else if/else
    if (volumeLevel >= 1 && volumeLevel <= 3) { // Range 1-3 
        volumeCategory = "Low";
        outputMessage = "Acceptable Audio Level";
} else if (volumeLevel >= 4 && volumeLevel <= 7) { // Range 4-7
        volumeCategory = "Medium";
        outputMessage = "Acceptable Audio level"; 
} else { // The only remaining possibility is Range 8-10
        volumeCategory = "High";
        outputMessage = "Warning: Audio level too high";
     }

     // Display the cateogory and the appropriate message
    std::cout << "Volume catorgory: " << volumeCategory << std::endl;
    std::cout << "Message: " << outputMessage << std::endl;

     // Get current time
     auto now = std::chrono::system_clock::now();
     auto now_c = std::chrono::system_clock::to_time_t(now);
     // Format time (YYYY-MM-DD HH:MM:SS). Note: std::localtime is not thread-safe.
    char time_str[20]; // Buffer to hold formatted time string
    std::strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", std::localtime(&now_c));

     // Open the file in append mode
     std::ofstream logFile("audio_levels.txt", std::ios::app);

     // Check if the file was opened successfully
     if (logFile.is_open()) {
            // Write the timestamp, volume level, and category to the file
            logFile << time_str << ", Level=" << volumeLevel << ", Category=" << volumeCategory << std::endl;
            // logFile.close(); // Not strictly necessary, automatically closes when logFile goes out of scope
     } else {
            // Print and error message to the standard error stream if file opening failed
            std::cerr << "Error: Unable to open log file 'audio_levels.txt' for writing." << std::endl;
            }

    // Return 0 indicates that the program executed successfully
    return 0;
}
