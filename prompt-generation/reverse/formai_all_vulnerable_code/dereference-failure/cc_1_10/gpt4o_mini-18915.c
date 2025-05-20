//GPT-4o-mini DATASET v1.0 Category: Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_ATTEMPTS 10
#define MAX_WORD_LENGTH 15

const char *word_list[] = {
    "programming", "data", "structure", "algorithm", "computer", 
    "science", "variable", "function", "pointer", "header", 
    "library", "syntax", "debugging", "execution", "software",
    "hardware"
};

void display_hangman(int attempts) {
    switch (attempts) {
        case 0:
            printf("  +---+\n      |\n      |\n      |\n     ===\n");
            break;
        case 1:
            printf("  +---+\n  O   |\n      |\n      |\n     ===\n");
            break;
        case 2:
            printf("  +---+\n  O   |\n  |   |\n      |\n     ===\n");
            break;
        case 3:
            printf("  +---+\n  O   |\n /|   |\n      |\n     ===\n");
            break;
        case 4:
            printf("  +---+\n  O   |\n /|\\  |\n      |\n     ===\n");
            break;
        case 5:
            printf("  +---+\n  O   |\n /|\\  |\n /    |\n     ===\n");
            break;
        case 6:
            printf("  +---+\n  O   |\n /|\\  |\n / \\  |\n     ===\n");
            break;
        default:
            break;
    }
}

void choose_word(char *chosen_word) {
    int index = rand() % (sizeof(word_list) / sizeof(word_list[0]));
    strcpy(chosen_word, word_list[index]);
}

void initialize_displayed_word(char *displayed_word, const char *chosen_word) {
    for (int i = 0; i < strlen(chosen_word); ++i) {
        displayed_word[i] = '_';
    }
    displayed_word[strlen(chosen_word)] = '\0';
}

int main() {
    char chosen_word[MAX_WORD_LENGTH];
    char displayed_word[MAX_WORD_LENGTH];
    char guessed_letters[26];
    int attempts = 0;
    int correct_guesses = 0;
    int word_length;
    char guess;
    int valid_input;

    srand(time(0)); // Seed the random number generator.

    printf("Welcome to Hangman!\n");
    choose_word(chosen_word);
    word_length = strlen(chosen_word);
    initialize_displayed_word(displayed_word, chosen_word);
    memset(guessed_letters, 0, sizeof(guessed_letters)); // Initialize guessed letters to zero.

    while (attempts < MAX_ATTEMPTS) {
        printf("\nWord: %s\n", displayed_word);
        printf("Guessed letters: ");
        for (int i = 0; i < 26; i++) {
            if (guessed_letters[i]) {
                printf("%c ", 'a' + i);
            }
        }
        printf("\nAttempts left: %d\n", MAX_ATTEMPTS - attempts);
        display_hangman(attempts);

        printf("Enter a letter to guess: ");
        valid_input = scanf(" %c", &guess);
        
        if (valid_input != 1 || guess < 'a' || guess > 'z') {
            printf("Invalid input. Please enter a letter between 'a' and 'z'.\n");
            while (getchar() != '\n'); // Clear the input buffer.
            continue;
        }

        if (guessed_letters[guess - 'a']) {
            printf("You've already guessed the letter '%c'. Try again.\n", guess);
            continue;
        }

        guessed_letters[guess - 'a'] = 1; // Mark the letter as guessed.

        int found = 0;
        for (int i = 0; i < word_length; i++) {
            if (chosen_word[i] == guess) {
                displayed_word[i] = guess; // Reveal the letter in the display.
                found = 1;
                correct_guesses++;
            }
        }

        if (!found) {
            attempts++; // Increment attempts if the guess was incorrect.
            printf("Wrong guess! '%c' is not in the word.\n", guess);
        }

        if (correct_guesses == word_length) {
            printf("Congratulations! You've guessed the word: %s\n", chosen_word);
            break;
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Game over! The word was: %s\n", chosen_word);
    }

    return 0;
}