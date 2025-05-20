//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define WORD_LENGTH 6
#define WORD_COUNT 10

// Function to generate a random word
char* generateRandomWord() {
    char* word = malloc(WORD_LENGTH + 1);
    for (int i = 0; i < WORD_LENGTH; i++) {
        word[i] = rand() % 26 + 'a';
    }
    word[WORD_LENGTH] = '\0';
    return word;
}

// Function to check if a word is typed correctly
int isCorrect(char* typed, char* correct) {
    int i;
    for (i = 0; i < WORD_LENGTH; i++) {
        if (tolower(typed[i])!= tolower(correct[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    char* correctWord;
    char* typedWord;
    int correctWords = 0;
    int totalWords = 0;

    // Initialize the first word
    correctWord = generateRandomWord();

    // Main loop
    while (1) {
        // Print the current word
        printf("Type the following word: %s\n", correctWord);

        // Get the user's input
        typedWord = malloc(WORD_LENGTH + 1);
        fgets(typedWord, WORD_LENGTH + 1, stdin);

        // Clean up the user's input
        typedWord[strcspn(typedWord, "\n")] = '\0';

        // Convert both words to lowercase
        for (int i = 0; i < WORD_LENGTH; i++) {
            correctWord[i] = tolower(correctWord[i]);
            typedWord[i] = tolower(typedWord[i]);
        }

        // Check if the word is typed correctly
        if (isCorrect(typedWord, correctWord)) {
            printf("Correct!\n");
            correctWords++;
        } else {
            printf("Incorrect.\n");
        }

        // Check if the test is over
        if (totalWords >= WORD_COUNT) {
            break;
        }

        // Move on to the next word
        free(correctWord);
        correctWord = generateRandomWord();
        totalWords++;
    }

    // Print the results
    printf("You typed %d out of %d words correctly.\n", correctWords, WORD_COUNT);

    return 0;
}