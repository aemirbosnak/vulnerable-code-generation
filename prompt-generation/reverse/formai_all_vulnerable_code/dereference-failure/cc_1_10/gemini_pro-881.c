//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum length of the test text
#define MAX_TEXT_LENGTH 1000

// Define the time limit for the test in seconds
#define TIME_LIMIT 60

// Define the number of characters to type in a word
#define WORD_LENGTH 5

// Define the number of words to type in a test
#define NUM_WORDS 20

// Define the number of tests to run
#define NUM_TESTS 10

// Create a struct to store the test results
typedef struct {
    int num_words;
    int num_errors;
    double wpm;
} test_results;

// Create a function to generate a random test text
char *generate_test_text(int length) {
    // Allocate memory for the test text
    char *text = malloc(length + 1);

    // Generate a random sequence of characters
    for (int i = 0; i < length; i++) {
        text[i] = (rand() % 26) + 'a';
    }

    // Add a null terminator to the end of the text
    text[length] = '\0';

    // Return the test text
    return text;
}

// Create a function to run a typing speed test
test_results run_typing_speed_test(char *text, int length) {
    // Create a struct to store the test results
    test_results results;

    // Initialize the test results
    results.num_words = 0;
    results.num_errors = 0;
    results.wpm = 0.0;

    // Start the timer
    time_t start_time = time(NULL);

    // Loop until the time limit is reached
    while (time(NULL) - start_time < TIME_LIMIT) {
        // Get the user's input
        char input[MAX_TEXT_LENGTH];
        scanf("%s", input);

        // Check if the user's input matches the test text
        int num_errors = 0;
        for (int i = 0; i < length; i++) {
            if (input[i] != text[i]) {
                num_errors++;
            }
        }

        // Update the test results
        results.num_words++;
        results.num_errors += num_errors;
    }

    // Calculate the WPM
    results.wpm = (double)results.num_words / ((double)TIME_LIMIT / 60.0);

    // Return the test results
    return results;
}

// Create a function to print the test results
void print_test_results(test_results results) {
    // Print the number of words typed
    printf("Number of words typed: %d\n", results.num_words);

    // Print the number of errors
    printf("Number of errors: %d\n", results.num_errors);

    // Print the WPM
    printf("WPM: %.2f\n", results.wpm);
}

// Create a function to run multiple typing speed tests
void run_multiple_typing_speed_tests(int num_tests) {
    // Create an array to store the test results
    test_results results[num_tests];

    // Loop through the number of tests
    for (int i = 0; i < num_tests; i++) {
        // Generate a random test text
        char *text = generate_test_text(MAX_TEXT_LENGTH);

        // Run the typing speed test
        test_results result = run_typing_speed_test(text, MAX_TEXT_LENGTH);

        // Store the test results
        results[i] = result;

        // Free the memory allocated for the test text
        free(text);
    }

    // Print the test results
    for (int i = 0; i < num_tests; i++) {
        printf("Test %d results:\n", i + 1);
        print_test_results(results[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Run multiple typing speed tests
    run_multiple_typing_speed_tests(NUM_TESTS);

    return 0;
}