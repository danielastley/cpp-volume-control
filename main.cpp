#include <iostream> // For input/output operations (like printing to console)
#include <limits>   // Required for numeric_limits (for robust input clearing)
#include <string>   // Required for using the string type


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

    // Categorize the valid vlume level using if/else if/else
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

     // (Code for categorization and file saving will go here later
    
    // Return 0 indicates that the program executed successfully
    return 0;
}
