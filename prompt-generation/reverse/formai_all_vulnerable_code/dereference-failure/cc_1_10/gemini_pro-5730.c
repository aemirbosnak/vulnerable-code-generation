//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Constants for game controls
#define START_GAME 's'
#define QUIT_GAME 'q'
#define MAX_WORDS 100
#define MAX_WORD_LEN 20

// Random word generator
char* generateRandomWord() {
    // Seed the random number generator
    srand(time(NULL));

    // Determine the word length
    int wordLen = rand() % MAX_WORD_LEN + 1;

    // Allocate memory for the word
    char* word = malloc(wordLen + 1);

    // Generate the word character by character
    for (int i = 0; i < wordLen; i++) {
        word[i] = 'a' + rand() % 26;
    }

    // Ensure the word is null-terminated
    word[wordLen] = '\0';

    // Return the generated word
    return word;
}

// Main game loop
int main() {
    // Welcome the user
    printf("**Welcome to the Finger-Twister Typhoon Typing Test!**\n");
    printf("Get ready to dance with the keyboard!\n");

    // Initialize the game variables
    char input[MAX_WORD_LEN + 1];
    int wordsTyped = 0;
    int errors = 0;
    double startTime, endTime, elapsedTime;

    // Keep playing until the user quits
    while (getchar() != QUIT_GAME) {
        // Start the timer
        startTime = time(NULL);

        // Generate a random word
        char* word = generateRandomWord();

        // Display the word to the user
        printf("%s", word);

        // Prompt the user to type the word
        printf("\nType the word: ");

        // Get the user's input
        scanf("%s", input);

        // Stop the timer
        endTime = time(NULL);

        // Calculate the elapsed time
        elapsedTime = difftime(endTime, startTime);

        // Check the user's input
        if (strcmp(input, word) == 0) {
            // Correct input
            printf("Correct! 👍\n");
            wordsTyped++;
        } else {
            // Incorrect input
            printf("Oops, that's not quite right! 👎\n");
            errors++;
        }

        // Free the memory allocated for the word
        free(word);
    }

    // Calculate the typing speed
    double typingSpeed = (double)wordsTyped / elapsedTime;

    // Display the game results
    printf("\n**Game Results**\n");
    printf("Words typed: %d\n", wordsTyped);
    printf("Errors: %d\n", errors);
    printf("Typing speed: %.2f words per minute\n", typingSpeed * 60);

    // Farewell message
    printf("\n**Thanks for playing!**\n");

    return 0;
}