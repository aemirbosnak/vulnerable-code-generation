//LLAMA2-13B DATASET v1.0 Category: Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 100
#define MAX_NUMBER_OF_GUESS 10

int main() {
    char *word = "secret";
    int guess[MAX_NUMBER_OF_GUESS];
    int correct = 0;
    int i, j;

    // Generate a random word
    srand(time(NULL));
    for (i = 0; i < MAX_STRING_LENGTH; i++) {
        word[i] = 'a' + (rand() % 26);
    }

    // Prompt the user to guess the word
    printf("Guess the word: ");

    // Loop until the user correctly guesses the word
    for (i = 0; i < MAX_NUMBER_OF_GUESS; i++) {
        printf("Guess %d: ", i + 1);
        scanf("%s", guess);

        // Check if the user's guess is correct
        for (j = 0; j < MAX_STRING_LENGTH; j++) {
            if (word[j] == guess[j]) {
                correct++;
            }
        }

        // Display the correct guesses and the remaining incorrect guesses
        printf("Correct guesses: %d\n", correct);
        for (j = 0; j < correct; j++) {
            printf(" %c", word[j]);
        }
        printf("\nIncorrect guesses: ");
        for (; j < MAX_STRING_LENGTH; j++) {
            printf(" %c", word[j]);
        }
        printf("\n");

        // Exit the loop if the user correctly guesses the word
        if (correct == MAX_STRING_LENGTH) {
            break;
        }
    }

    // Display the final result
    if (correct == MAX_STRING_LENGTH) {
        printf("Congratulations! You guessed the word correctly!\n");
    } else {
        printf("Sorry, you didn't guess the word correctly.\n");
    }

    return 0;
}