//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: all-encompassing
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define TEST_DURATION 30  // in seconds
#define TEST_TEXT_LENGTH 200  // in characters
#define NUM_TYPING_TESTS 3  // number of typing tests to perform

// Global variables
int test_results[NUM_TYPING_TESTS];  // array to store the results of each typing test
int best_result;  // variable to store the best result among all the typing tests
int worst_result;  // variable to store the worst result among all the typing tests
int average_result;  // variable to store the average result of all the typing tests

// Function to generate a random string of characters
char* generate_random_string(int length) {
    // Allocate memory for the string
    char* str = malloc(length + 1);  // +1 for the null-terminator

    // Generate a random string of characters
    for (int i = 0; i < length; i++) {
        str[i] = (rand() % 26) + 'a';  // generate a random lowercase letter
    }

    // Add the null-terminator to the end of the string
    str[length] = '\0';

    // Return the generated string
    return str;
}

// Function to perform a typing test
int perform_typing_test(int duration) {
    // Generate a random string of characters
    char* test_text = generate_random_string(TEST_TEXT_LENGTH);

    // Start the timer
    clock_t start_time = clock();

    // Get the current time in milliseconds
    int start_time_ms = clock() * 1000 / CLOCKS_PER_SEC;

    // Prompt the user to start typing
    printf("Start typing...\n");

    // Loop until the timer expires
    while (clock() * 1000 / CLOCKS_PER_SEC - start_time_ms < duration * 1000) {
        // Get the user's input
        char input_char;
        scanf(" %c", &input_char);

        // Check if the user's input matches the expected character
        if (input_char == test_text[start_time_ms / 1000 - start_time_ms / 1000 * duration]) {
            // Increment the number of correct characters typed
            start_time_ms++;
        }
    }

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the typing speed in characters per minute (CPM)
    int typing_speed = (start_time_ms / 1000) * 60 / duration;

    // Free the memory allocated for the test text
    free(test_text);

    // Return the typing speed
    return typing_speed;
}

// Function to calculate the average of an array of integers
int calculate_average(int arr[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }
    return sum / length;
}

// Function to find the best result in an array of integers
int find_best_result(int arr[], int length) {
    int best_result = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] > best_result) {
            best_result = arr[i];
        }
    }
    return best_result;
}

// Function to find the worst result in an array of integers
int find_worst_result(int arr[], int length) {
    int worst_result = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] < worst_result) {
            worst_result = arr[i];
        }
    }
    return worst_result;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Perform multiple typing tests
    for (int i = 0; i < NUM_TYPING_TESTS; i++) {
        test_results[i] = perform_typing_test(TEST_DURATION);
    }

    // Calculate the average, best, and worst results
    average_result = calculate_average(test_results, NUM_TYPING_TESTS);
    best_result = find_best_result(test_results, NUM_TYPING_TESTS);
    worst_result = find_worst_result(test_results, NUM_TYPING_TESTS);

    // Print the results
    printf("Typing Test Results:\n");
    for (int i = 0; i < NUM_TYPING_TESTS; i++) {
        printf("Test %d: %d CPM\n", i + 1, test_results[i]);
    }
    printf("Average: %d CPM\n", average_result);
    printf("Best: %d CPM\n", best_result);
    printf("Worst: %d CPM\n", worst_result);

    return 0;
}