//MISTRAL-7B DATASET v1.0 Category: Terminal Based Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORD_LENGTH 10
#define MAX_TRIES 7
#define HIDDEN_WORD_SIZE 12

void print_stars(int stars) {
    for (int i = 0; i < stars; i++) {
        printf("*");
    }
    printf("\n");
}

void print_word_progress(char guessed_letters[], char word[]) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (strchr(guessed_letters, word[i]) != NULL) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    char word[HIDDEN_WORD_SIZE];
    char guessed_letters[WORD_LENGTH];
    int num_stars = 0;
    int num_guesses = 0;

    strcpy(word, "ROCKETSHIP"); // Set the hidden word here

    while (num_stars < WORD_LENGTH && num_guesses < MAX_TRIES) {
        print_stars(num_stars);
        print_word_progress(guessed_letters, word);

        printf("Guess a letter: ");
        char guess;
        scanf(" %c", &guess);

        if (strchr(word, guess) != NULL) {
            guessed_letters[num_guesses] = guess;
            num_stars += 1;
            num_guesses++;
        } else {
            num_guesses++;
            printf("Incorrect guess. You have %d tries left.\n", MAX_TRIES - num_guesses);
        }
    }

    if (num_stars < WORD_LENGTH) {
        print_stars(num_stars);
        print_word_progress(guessed_letters, word);
        printf("Sorry, you didn't find the word.\nThe word was: %s\n", word);
    } else {
        print_stars(num_stars);
        printf("Congratulations! You found the word: %s\n", word);
    }

    return 0;
}