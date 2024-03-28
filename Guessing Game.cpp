#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> // Add this header for std::numeric_limits

using namespace std; // Add this to use namespace std

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr))); // Remove std:: from srand and time

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1; // Remove std:: from rand

    int guess;
    int attempts = 0;

    cout << "Welcome to the Guessing Game!\n";
    cout << "Try to guess the number between 1 and 100.\n\n";

    do {
        // Prompt the user for a guess
        cout << "Enter your guess: ";
        cin >> guess;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Use std::numeric_limits

        // Increment the number of attempts
        attempts++;

        // Check if the guess is too high, too low, or correct
        if (guess < secretNumber) {
            cout << "Too low! Try again.\n\n";
        } else if (guess > secretNumber) {
            cout << "Too high! Try again.\n\n";
        } else {
            cout << "\nCongratulations! You guessed the number " << secretNumber << " correctly!\n";
            cout << "It took you " << attempts << " attempts.\n";
        }
    } while (guess != secretNumber);

    return 0;
}
