//LLAMA2-13B DATASET v1.0 Category: Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LEN 20
#define MAX_GUESS 5

// Define a struct to represent a word
typedef struct {
    char letter[MAX_WORD_LEN];
    int guesses;
} word_t;

// Define a function to generate a random word
word_t* generate_word(void) {
    int i, j;
    word_t* word = malloc(sizeof(word_t));
    for (i = 0; i < MAX_WORD_LEN; i++) {
        word->letter[i] = 'a' + (rand() % 26);
    }
    word->guesses = 0;
    return word;
}

// Define a function to guess a letter in a word
int guess_letter(word_t* word, char guess) {
    int i;
    for (i = 0; i < MAX_WORD_LEN; i++) {
        if (word->letter[i] == guess) {
            word->letter[i] = '.';
            return 1;
        }
    }
    return 0;
}

// Define a function to check if a word is complete
int is_complete(word_t* word) {
    int i;
    for (i = 0; i < MAX_WORD_LEN; i++) {
        if (word->letter[i] == '.') {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    srand(time(NULL));

    // Create a word to start with
    word_t* word = generate_word();

    // Print the word
    printf("Starting word: %s\n", word->letter);

    // Loop until the word is complete
    while (!is_complete(word)) {
        // Ask the user to guess a letter
        printf("Guess a letter: ");
        char guess = getchar();

        // Check if the letter is in the word
        if (guess_letter(word, guess)) {
            printf("Letter %c appears in the word\n", guess);
        } else {
            printf("Letter %c does not appear in the word\n", guess);
        }

        // Update the word with the guessed letter
        word = guess_letter(word, guess);
    }

    // Print the completed word
    printf("Completed word: %s\n", word->letter);

    return 0;
}