#include<iostream>
#include<cstdlib>
#include<ctime>
#include <string> // Include the string library for using strings
#include <cstdlib> // Include the cstdlib library for srand() and rand()
#include <ctime> // Include the ctime library for time() function
#include <iostream> // Include the iostream library for input and output

using namespace std; // Use the standard namespace to avoid prefixing std:: to standard functions

// Function to generate the computer's move
char getcomputermove() {
    int move; // Variable to store the random move of the computer
    srand(time(NULL)); // Seed the random number generator with the current time
    move = rand() % 3; // Generate a random number between 0 and 2

    // Return the corresponding move based on the random number generated
    if (move == 0) {
        return 'r'; // Rock
    } else if (move == 1) {
        return 's'; // Scissors
    }
    return 'p'; // Paper (if move is 2)
}

// Function to determine the result of the game
string result(char player, char comp) {
    // Check if both player and computer made the same move
    if (player == comp) {
        string d = "AWWW HELL NAH IT'S A DRAW"; // Draw message
        return d; // Return draw message
    }
    // Check all winning combinations for the player
    if ((player == 's' && comp == 'p') || 
        (player == 'r' && comp == 's') || 
        (player == 'p' && comp == 'r')) {
        string w = "CONGRATULATIONS! YOU WON"; // Win message
        return w; // Return win message
    }
    string l = "TRY AGAIN! YOU LOST"; // Loss message
    return l; // Return loss message
}

// Main function where the execution starts
int main() {
    char player, comp; // Variables to store player's move and computer's move
    cout << "Enter your move: "; // Prompt the player to enter their move
    cin >> player; // Read the player's move from input

    // Check if the player's move is valid
    if (player != 'r' && player != 's' && player != 'p') {
        cout << "Invalid move"; // Display an error message for invalid input
        return 0; // Exit the program if the move is invalid
    }

    comp = getcomputermove(); // Get the computer's move
    cout << "Computer's move: " << comp << endl; // Display the computer's move
    cout << result(player, comp); // Display the result of the game
    return 0; // Exit the program successfully
}
