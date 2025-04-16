#include <iostream> // For input/output operations (like printing to console)
#include <limits>   // Required for numeric_limits (for robust input clearing)


// The main function is the entry point of the program
int main() {
    int volumeLevel; // Declare an integer variable to store the volume
        // Print a simple message to the console
        std::cout << "Audio Volume Control Program Initialized." << std::endl;

    //Use a do-while loop to ensure we get valid input
    do {
        // Prompt the user for input
        std::cout << "Enter audio volume level (1-10): ";
        std::cin >> volumeLevel; // Read the integer input into volumeLevel

        // Check if the input operation failed (e.g., user entered text)
        // or if the value is outside the valid range (1-10)
        if (std::cin.fail() || volumeLevel < 1  || volumeLevel > 10) {
            std::cout << "Invalid input. Please enter a number between 1 and 10." << std::endl;

            // Clear the error flag on cin
            std::cin.clear();

            // Discard the invalid input from the input buffer
            // numeric_limits<streamsize>::max() gets the maximum size of the stream
            // '\n' means discard characters until a newline is found

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            volumeLevel = 0; // Reset volumeLevel to ensure the loop continues

        } else {
            // Input is valid and within range, break the loop
            break;
        }

    } while (true); // Loop indefinitely until valid input is received and we 'break'

    // Display the valid volume level entered (for confirmation)
    std::cout << "You entered volume level: " << volumeLevel << std::endl;

    // (Code for categorization and file saving will go here later
    
    // Return 0 indicates that the program executed successfully
    return 0;
}
