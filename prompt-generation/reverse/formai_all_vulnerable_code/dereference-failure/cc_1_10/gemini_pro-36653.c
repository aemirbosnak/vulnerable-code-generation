//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// Function to generate a random string of length n
char* generate_random_string(int n) {
    char* str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + (rand() % 26);
    }
    str[n] = '\0';
    return str;
}

// Function to start the typing test
void start_test() {
    int num_words = 10; // Number of words in the test
    int word_length = 5; // Average length of each word
    char** words = malloc(sizeof(char*) * num_words); // Array of words

    // Generate the words
    for (int i = 0; i < num_words; i++) {
        words[i] = generate_random_string(word_length);
    }

    // Print the words to the console
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    // Start the timer
    clock_t start_time = clock();

    // Get the input from the user
    char input[100];
    scanf("%s", input);

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the time taken
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the words per minute
    int words_per_minute = (int)((num_words * 60) / time_taken);

    // Print the results
    printf("Words per minute: %d\n", words_per_minute);
    printf("Time taken: %f seconds\n", time_taken);

    // Free the allocated memory
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Start the typing test
    start_test();

    return 0;
}