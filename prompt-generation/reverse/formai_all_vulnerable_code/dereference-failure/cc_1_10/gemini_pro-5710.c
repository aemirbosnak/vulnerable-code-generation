//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum allowed input length
#define MAX_INPUT_LENGTH 100

// Define the minimum number of correct characters for a satisfactory result
#define MIN_CORRECT_CHARACTERS 75

// Define the minimum typing speed for a satisfactory result
#define MIN_TYPING_SPEED 30

// Define the maximum typing speed for a satisfactory result
#define MAX_TYPING_SPEED 60

// Structure to store the test results
typedef struct {
    int correct_characters;
    int incorrect_characters;
    float typing_speed;
    char *input_text;
} TestResults;

// Function to generate a random string of characters
char *generate_random_string(int length) {
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = 'a' + rand() % 26;
    }
    string[length] = '\0';
    return string;
}

// Function to calculate the typing speed
float calculate_typing_speed(int correct_characters, int incorrect_characters, float time_taken) {
    return (correct_characters + incorrect_characters) / time_taken * 60;
}

// Function to check if the test results are satisfactory
int is_satisfactory(TestResults results) {
    return results.correct_characters >= MIN_CORRECT_CHARACTERS && results.typing_speed >= MIN_TYPING_SPEED && results.typing_speed <= MAX_TYPING_SPEED;
}

// Main function
int main() {
    // Generate a random string of characters
    char *random_string = generate_random_string(MAX_INPUT_LENGTH);

    // Print the random string to the console
    printf("Type the following text as quickly and accurately as possible:\n\n%s\n\n", random_string);

    // Start the timer
    clock_t start_time = clock();

    // Get the user's input
    char input[MAX_INPUT_LENGTH + 1];
    scanf("%s", input);

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the time taken
    float time_taken = (float)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the number of correct and incorrect characters
    int correct_characters = 0;
    int incorrect_characters = 0;
    for (int i = 0; i < strlen(random_string); i++) {
        if (input[i] == random_string[i]) {
            correct_characters++;
        } else {
            incorrect_characters++;
        }
    }

    // Calculate the typing speed
    float typing_speed = calculate_typing_speed(correct_characters, incorrect_characters, time_taken);

    // Store the results in a TestResults structure
    TestResults results = {
        .correct_characters = correct_characters,
        .incorrect_characters = incorrect_characters,
        .typing_speed = typing_speed,
        .input_text = input
    };

    // Print the test results to the console
    printf("\nTest Results:\n\n");
    printf("Correct characters: %d\n", results.correct_characters);
    printf("Incorrect characters: %d\n", results.incorrect_characters);
    printf("Typing speed: %.2f words per minute\n", results.typing_speed);

    // Check if the test results are satisfactory
    int is_satisfactory_result = is_satisfactory(results);

    // Print a message to the console indicating whether the test results are satisfactory or not
    if (is_satisfactory_result) {
        printf("\nCongratulations! You have passed the typing test with a satisfactory result.\n");
    } else {
        printf("\nSorry, you have not passed the typing test with a satisfactory result.\n");
    }

    // Free the allocated memory
    free(random_string);

    return 0;
}