//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an array of words
    char *words[MAX_WORDS];
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i] = malloc(MAX_WORD_LENGTH);
        for (int j = 0; j < MAX_WORD_LENGTH; j++) {
            words[i][j] = 'a' + rand() % 26;
        }
        words[i][MAX_WORD_LENGTH - 1] = '\0';
    }

    // Print the words to the screen
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%s ", words[i]);
    }

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char input[MAX_WORDS * MAX_WORD_LENGTH];
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the typing speed
    double typingSpeed = (double)(strlen(input) * 60000) / (end - start);

    // Print the typing speed to the screen
    printf("Your typing speed is %.2f words per minute.\n", typingSpeed);

    // Free the memory allocated for the words
    for (int i = 0; i < MAX_WORDS; i++) {
        free(words[i]);
    }

    return 0;
}