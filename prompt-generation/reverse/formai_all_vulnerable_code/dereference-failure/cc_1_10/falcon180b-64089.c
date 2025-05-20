//Falcon-180B DATASET v1.0 Category: Educational ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    char *words[SIZE] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};
    int num_words = sizeof(words) / sizeof(words[0]);
    srand(time(NULL));
    int index = rand() % num_words;
    char *word = words[index];
    char *guess;
    int tries = 0;
    int max_tries = 7;
    char *letters = "abcdefghijklmnopqrstuvwxyz";
    int length = strlen(word);
    int correct_guesses = 0;
    int wrong_guesses = 0;

    printf("Welcome to Hangman!\n");
    printf("I'm thinking of a word that is %d letters long.\n", length);
    printf("Guess the letters in my word.\n");
    printf("You have %d tries.\n", max_tries);

    while (tries < max_tries && strlen(guess)!= length) {
        printf("Guesses so far: %s\n", guess);
        printf("Incorrect guesses: %d\n", wrong_guesses);
        printf("Correct guesses: %d\n", correct_guesses);
        printf("Number of tries left: %d\n", max_tries - tries);
        printf("Enter your guess: ");
        scanf("%s", guess);
        int i;
        for (i = 0; i < strlen(guess); i++) {
            if (guess[i] == word[i]) {
                correct_guesses++;
            } else {
                wrong_guesses++;
            }
        }
        tries++;
    }

    if (tries == max_tries) {
        printf("You lose! The word was %s.\n", word);
    } else {
        printf("You win! The word was %s.\n", word);
    }

    return 0;
}