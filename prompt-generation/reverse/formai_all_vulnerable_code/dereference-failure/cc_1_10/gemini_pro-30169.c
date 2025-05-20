//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Define the number of words in the test
#define NUM_WORDS 100

// Define the time limit for the test (in seconds)
#define TIME_LIMIT 60

// Create a struct to store the results of the test
typedef struct {
    int num_correct;
    int num_incorrect;
    int num_words_per_minute;
} test_results;

// Create a function to generate a random word
char* generate_random_word() {
    // Create an array of all the possible letters
    char letters[] = "abcdefghijklmnopqrstuvwxyz";

    // Get a random length for the word
    int length = rand() % MAX_WORD_LENGTH + 1;

    // Create a buffer to store the word
    char* word = malloc(length + 1);

    // Generate the word
    for (int i = 0; i < length; i++) {
        word[i] = letters[rand() % 26];
    }

    // Null-terminate the word
    word[length] = '\0';

    // Return the word
    return word;
}

// Create a function to display the test instructions
void display_instructions() {
    printf("Typing Speed Test\n");
    printf("Instructions:\n");
    printf("1. Type the words that appear on the screen as quickly and accurately as possible.\n");
    printf("2. You have 60 seconds to complete the test.\n");
    printf("3. Your score will be displayed at the end of the test.\n");
}

// Create a function to start the test
test_results start_test() {
    // Create a buffer to store the user's input
    char input[MAX_WORD_LENGTH + 1];

    // Create an array to store the words
    char* words[NUM_WORDS];

    // Generate the words
    for (int i = 0; i < NUM_WORDS; i++) {
        words[i] = generate_random_word();
    }

    // Start the timer
    time_t start_time = time(NULL);

    // Get the user's input
    int num_correct = 0;
    int num_incorrect = 0;
    for (int i = 0; i < NUM_WORDS; i++) {
        printf("%s\n", words[i]);
        scanf("%s", input);

        // Check if the user's input is correct
        if (strcmp(input, words[i]) == 0) {
            num_correct++;
        } else {
            num_incorrect++;
        }
    }

    // Stop the timer
    time_t end_time = time(NULL);

    // Calculate the time taken to complete the test
    double time_taken = difftime(end_time, start_time);

    // Calculate the number of words per minute
    double num_words_per_minute = (double)num_correct / time_taken * 60;

    // Return the test results
    test_results results;
    results.num_correct = num_correct;
    results.num_incorrect = num_incorrect;
    results.num_words_per_minute = num_words_per_minute;
    return results;
}

// Create a function to display the test results
void display_results(test_results results) {
    printf("Test Results:\n");
    printf("Number of correct words: %d\n", results.num_correct);
    printf("Number of incorrect words: %d\n", results.num_incorrect);
    printf("Number of words per minute: %.2f\n", results.num_words_per_minute);
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Display the test instructions
    display_instructions();

    // Start the test
    test_results results = start_test();

    // Display the test results
    display_results(results);

    return 0;
}