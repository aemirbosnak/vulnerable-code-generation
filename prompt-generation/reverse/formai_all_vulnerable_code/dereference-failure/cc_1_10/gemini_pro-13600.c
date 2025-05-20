//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORDS 100

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Create an array of words
    char *words[WORDS];
    for (int i = 0; i < WORDS; i++) {
        // Generate a random word of length 5-10 characters
        int length = rand() % 6 + 5;
        words[i] = malloc(length + 1);
        for (int j = 0; j < length; j++) {
            words[i][j] = 'a' + rand() % 26;
        }
        words[i][length] = '\0';
    }

    // Get the current time
    time_t start = time(NULL);

    // Prompt the user to start typing
    printf("Start typing:\n");

    // Get the user's input
    char input[WORDS * 10];
    fgets(input, WORDS * 10, stdin);

    // Get the current time
    time_t end = time(NULL);

    // Calculate the typing speed
    int time_taken = end - start;
    int words_typed = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            words_typed++;
        }
    }
    float wpm = (float)words_typed / time_taken * 60;

    // Print the results
    printf("Typing speed: %.2f WPM\n", wpm);

    // Free the allocated memory
    for (int i = 0; i < WORDS; i++) {
        free(words[i]);
    }

    return 0;
}