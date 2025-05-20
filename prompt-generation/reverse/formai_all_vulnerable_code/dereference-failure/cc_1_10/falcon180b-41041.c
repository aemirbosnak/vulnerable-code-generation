//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WORDS 100
#define WORD_LENGTH 10

int main() {
    char *words[NUM_WORDS];
    int word_lengths[NUM_WORDS];
    int i, j;
    char user_input[WORD_LENGTH];
    int num_correct = 0;
    int num_incorrect = 0;
    int num_skipped = 0;
    int total_words = 0;
    double speed = 0;
    double accuracy = 0;
    time_t start_time, end_time;
    double elapsed_time;

    // Initialize the array of words
    for (i = 0; i < NUM_WORDS; i++) {
        words[i] = malloc(WORD_LENGTH * sizeof(char));
        sprintf(words[i], "word%d", i + 1);
        word_lengths[i] = strlen(words[i]);
    }

    // Prompt the user to start the test
    printf("Welcome to the Typing Speed Test!\n");
    printf("Please type the following words as accurately and quickly as possible:\n");

    // Start the timer
    time(&start_time);

    // Loop through each word
    for (i = 0; i < NUM_WORDS; i++) {
        // Print the word
        printf("%s ", words[i]);

        // Get the user input
        fgets(user_input, WORD_LENGTH, stdin);

        // Remove the newline character from the input
        user_input[strcspn(user_input, "\n")] = '\0';

        // Check if the user input matches the word
        if (strcmp(user_input, words[i]) == 0) {
            num_correct++;
        } else {
            num_incorrect++;
        }

        // Check if the user skipped the word
        if (user_input[0] == '\0') {
            num_skipped++;
        }

        // Update the total number of words
        total_words++;
    }

    // Stop the timer
    time(&end_time);
    elapsed_time = difftime(end_time, start_time);

    // Calculate the speed and accuracy
    if (total_words > 0) {
        speed = (double)total_words / elapsed_time;
        accuracy = (double)num_correct / (num_correct + num_incorrect);
    }

    // Print the results
    printf("\nTest complete!\n");
    printf("You typed %d words correctly, %d words incorrectly, and skipped %d words.\n", num_correct, num_incorrect, num_skipped);
    printf("Total words typed: %d\n", total_words);
    printf("Speed: %.2f words per minute\n", speed);
    printf("Accuracy: %.2f%%\n", accuracy * 100);

    return 0;
}