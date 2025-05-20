//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_MAX_LENGTH 20
#define MAX_GUESS_ATTEMPTS 3

// Global variables
char *password = "thisIsASecret";
int guessesLeft = MAX_GUESS_ATTEMPTS;

// Function to print the password
void printPassword() {
    printf("Password: %s\n", password);
}

// Function to get the user's guess
char *getGuess() {
    char guess[PASSWORD_MAX_LENGTH];
    printf("Enter your guess: ");
    fgets(guess, PASSWORD_MAX_LENGTH, stdin);
    return guess;
}

// Function to check if the user's guess is correct
int checkGuess(char *guess) {
    int i = 0;
    for (i = 0; i < strlen(guess); i++) {
        if (guess[i] != password[i]) {
            break;
        }
    }
    return i == strlen(guess);
}

// Function to increment the number of guesses left
void decrementGuesses() {
    guessesLeft--;
    if (guessesLeft == 0) {
        printf("You have guessed incorrectly too many times. Game over.\n");
        exit(1);
    }
}

int main() {
    srand(time(NULL));
    printPassword();

    while (1) {
        char *guess = getGuess();
        if (checkGuess(guess)) {
            printf("Correct guess! You win!\n");
            break;
        }
        decrementGuesses();
    }
    return 0;
}