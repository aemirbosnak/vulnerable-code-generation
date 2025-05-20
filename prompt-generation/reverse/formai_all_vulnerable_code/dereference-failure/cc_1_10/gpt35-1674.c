//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 10 // Maximum number of words for the test
#define MAX_LENGTH 20 // Maximum length of each word
#define MIN_DELAY 1000 // Minimum delay between words (in milliseconds)

/**
 * Shuffle the items of an array using the Fisher-Yates algorithm
 */
void shuffle(int* arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/**
 * Get a random lowercase letter
 */
char rand_letter() {
    return 'a' + rand() % 26;
}

/**
 * Generate a random word of length l
 */
void rand_word(char* str, int l) {
    for (int i = 0; i < l; i++) {
        str[i] = rand_letter();
    }
    str[l] = '\0';
}

int main() {
    srand(time(NULL)); // Initialize the random seed

    // Generate the words for the test
    char words[MAX_WORDS][MAX_LENGTH + 1];
    int word_lengths[MAX_WORDS];
    for (int i = 0; i < MAX_WORDS; i++) {
        int l = rand() % MAX_LENGTH + 1;
        word_lengths[i] = l;
        rand_word(words[i], l);
    }

    shuffle(word_lengths, MAX_WORDS); // Shuffle the word lengths
    shuffle((int*) words, MAX_WORDS * (MAX_LENGTH + 1)); // Shuffle the words

    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the words as they appear on the screen.\n");
    printf("Press Ctrl+C to exit at any time.\n\n");

    int correct_count = 0; // Number of correctly typed words
    int total_count = 0; // Total number of words typed
    int total_time = 0; // Total time taken to type the words (in milliseconds)

    // Iterate over the shuffled words
    for (int i = 0; i < MAX_WORDS; i++) {
        // Print the word and get the starting time
        printf("%s ", words[i]);
        fflush(stdout); // Make sure the word is printed on the screen
        struct timespec start;
        clock_gettime(CLOCK_MONOTONIC, &start);

        // Wait for the user to type the word
        char input[MAX_LENGTH + 1];
        fgets(input, MAX_LENGTH + 1, stdin);

        // Get the ending time and calculate the elapsed time
        struct timespec end;
        clock_gettime(CLOCK_MONOTONIC, &end);
        int elapsed_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;

        // Remove the newline character from the input if present
        int input_len = strlen(input);
        if (input[input_len - 1] == '\n') {
            input[input_len - 1] = '\0';
        }

        // Check if the input matches the word
        if (strcmp(input, words[i]) == 0) {
            printf("Correct! ");
            correct_count++;
        } else {
            printf("Wrong! ");
        }

        // Print the elapsed time and update the counts
        printf("Time: %d ms\n", elapsed_time);
        total_count++;
        total_time += elapsed_time;

        // Wait for a randomized interval before showing the next word
        usleep(rand() % MIN_DELAY * 1000);
    }

    // Calculate and print the final results
    float accuracy = (float) correct_count / total_count * 100;
    float avg_time = (float) total_time / total_count;
    printf("\nResults:\n");
    printf(" - Total words: %d\n", total_count);
    printf(" - Correct words: %d (%.1f%%)\n", correct_count, accuracy);
    printf(" - Average time per word: %.1f ms\n", avg_time);

    return 0;
}