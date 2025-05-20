//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, secret_number, max_range, remaining_guesses, i;
    printf("Welcome to the Guessing Game!\n");

    // Ask user for maximum range of numbers
    printf("Enter the maximum range of numbers: ");
    scanf("%d", &max_range);

    // Generate random number within the specified range
    srand(time(0)); // seed the random function with current time
    secret_number = rand() % max_range + 1;

    // Set the number of remaining guesses
    remaining_guesses = 5;

    // Start the game loop
    while(remaining_guesses > 0) {
        printf("You have %d guesses remaining.\n", remaining_guesses);

        // Ask user to guess a number
        printf("Guess a number between 1 and %d: ", max_range);
        scanf("%d", &guess);

        // Decrease the number of remaining guesses
        remaining_guesses--;

        // Check if guess is correct
        if (guess == secret_number) {
            printf("Congratulations! You guessed the correct number in %d guesses.\n", 5 - remaining_guesses);
            break;
        } else {
            // Provide feedback to user
            if (guess > secret_number) {
                printf("Your guess is too high.\n");
            } else {
                printf("Your guess is too low.\n");
            }
        }
    }

    // If user did not guess correctly within allotted guesses, end the game
    if (remaining_guesses == 0) {
        printf("Sorry, you did not guess the correct number within %d guesses. The correct number was %d.\n", 5, secret_number);
    }

    // Exit the program
    return 0;
}