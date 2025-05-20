//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LEN 1024
#define MAX_GUESS 5

// Define a struct to hold the puzzle state
struct puzzle {
    char word[MAX_INPUT_LEN];
    int len;
    int guesses;
};

// Function to generate a random puzzle
struct puzzle* generate_puzzle(void) {
    struct puzzle* puzzle = malloc(sizeof(struct puzzle));
    int i, j;

    // Generate a random word and store it in the puzzle struct
    for (i = 0; i < MAX_INPUT_LEN; i++) {
        puzzle->word[i] = 'a' + (rand() % 26);
    }

    // Set the length of the word and the number of guesses
    puzzle->len = strlen(puzzle->word);
    puzzle->guesses = MAX_GUESS;

    // Shuffle the word for added difficulty
    for (i = 0; i < puzzle->len; i++) {
        j = rand() % puzzle->len;
        char temp = puzzle->word[i];
        puzzle->word[i] = puzzle->word[j];
        puzzle->word[j] = temp;
    }

    return puzzle;
}

// Function to check if the user's guess is correct
int check_guess(struct puzzle* puzzle, char guess) {
    int i;

    // Check if the guess is out of bounds
    if (guess < 'a' || guess > 'z') {
        return 0;
    }

    // Check if the guess is in the word
    for (i = 0; i < puzzle->len; i++) {
        if (puzzle->word[i] == guess) {
            return 1;
        }
    }

    return 0;
}

// Function to handle errors and display the puzzle
void handle_error(struct puzzle* puzzle, char guess) {
    int i;

    // If the guess is out of bounds, display an error message
    if (!check_guess(puzzle, guess)) {
        printf("Oops! That's not a valid guess. Try again:\n");
        return;
    }

    // If the guess is correct, display the correct letter and update the word
    for (i = 0; i < puzzle->len; i++) {
        if (puzzle->word[i] == guess) {
            printf("Great guess! You got %c right!\n", guess);
            puzzle->word[i] = '_';
            break;
        }
    }

    // If the guess is incorrect, display an error message and update the word
    if (i == puzzle->len) {
        printf("Oops! That's not a correct guess. Here's the updated word:\n");
        for (i = 0; i < puzzle->len; i++) {
            printf("%c", puzzle->word[i]);
        }
        printf("\n");
    }
}

int main(void) {
    struct puzzle* puzzle = generate_puzzle();

    // Display the puzzle and start the game loop
    printf("Welcome to the puzzle game! Here's the puzzle:\n");
    for (int i = 0; i < puzzle->len; i++) {
        printf("%c", puzzle->word[i]);
    }
    printf("\n");

    while (puzzle->guesses > 0) {
        // Ask the user for their guess
        printf("Guess a letter: ");
        char guess = getchar();

        // Handle the error and display the result
        handle_error(puzzle, guess);
    }

    // Display the final result
    printf("Congratulations! You solved the puzzle in %d guesses.\n", puzzle->guesses);

    free(puzzle);
    return 0;
}