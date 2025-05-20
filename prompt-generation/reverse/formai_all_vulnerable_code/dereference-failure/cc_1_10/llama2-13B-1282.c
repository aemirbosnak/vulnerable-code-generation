//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESS_LENGTH 20
#define MAX_WORD_LENGTH 10
#define MIN_GUESS_LENGTH 3

// Structure to hold the secret word and its length
typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int len;
} secret_word_t;

// Function to generate a secret word and its length
secret_word_t *generate_secret_word(void) {
    // Generate a random word between 3 and 10 letters long
    int len = rand() % (10 - 3) + 3;
    char word[len + 1];
    for (int i = 0; i < len; i++) {
        word[i] = 'a' + (rand() % 26);
    }
    word[len] = '\0';
    return (secret_word_t *)malloc(sizeof(secret_word_t));
}

// Function to check if a guess is correct
int check_guess(char *guess, secret_word_t *secret) {
    int correct = 0;
    for (int i = 0; i < secret->len; i++) {
        if (guess[i] == secret->word[i]) {
            correct++;
        }
    }
    if (correct == secret->len) {
        return 1;
    } else {
        return 0;
    }
}

// Function to display the game state and ask for a guess
void display_game_state(secret_word_t *secret) {
    printf("Welcome to the Secret Word Game!\n");
    printf("The secret word has %d letters.\n", secret->len);
    printf("Here's a hint: The secret word starts with the letter %c.\n", secret->word[0]);
    printf("What's your guess? ");
}

// Function to handle the player's guess and display the result
void handle_guess(char *guess, secret_word_t *secret) {
    int correct = check_guess(guess, secret);
    if (correct) {
        printf("Congratulations! You guessed the secret word correctly!\n");
    } else {
        printf("Oops, that's not the secret word. Here's a hint: The word contains the letter %c.\n",
               secret->word[secret->len - 1]);
    }
    display_game_state(secret);
}

int main(void) {
    // Generate the secret word and its length
    secret_word_t *secret = generate_secret_word();

    // Display the game state and ask for the first guess
    display_game_state(secret);

    // Get the first guess from the player
    char first_guess[MAX_GUESS_LENGTH];
    printf("What's your first guess? ");
    scanf("%19s", first_guess);

    // Handle the first guess
    handle_guess(first_guess, secret);

    // Keep playing until the player guesses the secret word correctly
    while (1) {
        // Display the game state and ask for the next guess
        display_game_state(secret);

        // Get the next guess from the player
        char next_guess[MAX_GUESS_LENGTH];
        printf("What's your next guess? ");
        scanf("%19s", next_guess);

        // Handle the next guess
        handle_guess(next_guess, secret);
    }

    // Free the memory allocated for the secret word
    free(secret);

    return 0;
}