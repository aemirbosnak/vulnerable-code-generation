//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variables
int words_per_minute;
int characters_per_minute;
int accuracy;
int elapsed_seconds;
char *test_text;

// Function to generate random text
char *generate_text(int length) {
    // Allocate memory for the text
    char *text = malloc(length + 1);

    // Generate random characters
    for (int i = 0; i < length; i++) {
        text[i] = (rand() % 26) + 97;
    }

    // Add null terminator
    text[length] = '\0';

    // Return the text
    return text;
}

// Function to get user input
char *get_user_input() {
    // Allocate memory for the user input
    char *input = malloc(512);

    // Get user input
    printf("Type the following text as quickly and accurately as possible:\n");
    printf("%s\n", test_text);
    fgets(input, 512, stdin);

    // Return the user input
    return input;
}

// Function to calculate words per minute
int calculate_words_per_minute(char *input) {
    // Split the input into words
    char *words[512];
    int num_words = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Calculate the elapsed time in minutes
    float minutes = elapsed_seconds / 60.0;

    // Calculate the words per minute
    return (int)(num_words / minutes);
}

// Function to calculate characters per minute
int calculate_characters_per_minute(char *input) {
    // Calculate the length of the input
    int length = strlen(input);

    // Calculate the elapsed time in minutes
    float minutes = elapsed_seconds / 60.0;

    // Calculate the characters per minute
    return (int)(length / minutes);
}

// Function to calculate accuracy
int calculate_accuracy(char *input) {
    // Calculate the number of correct characters
    int correct_characters = 0;
    for (int i = 0; i < strlen(test_text); i++) {
        if (test_text[i] == input[i]) {
            correct_characters++;
        }
    }

    // Calculate the accuracy
    return (int)((correct_characters / (float)strlen(test_text)) * 100);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the test text
    test_text = generate_text(200);

    // Start the timer
    clock_t start_time = clock();

    // Get the user input
    char *input = get_user_input();

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the elapsed time in seconds
    elapsed_seconds = (end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the words per minute
    words_per_minute = calculate_words_per_minute(input);

    // Calculate the characters per minute
    characters_per_minute = calculate_characters_per_minute(input);

    // Calculate the accuracy
    accuracy = calculate_accuracy(input);

    // Print the results
    printf("Words per minute: %d\n", words_per_minute);
    printf("Characters per minute: %d\n", characters_per_minute);
    printf("Accuracy: %d%%\n", accuracy);

    // Free the allocated memory
    free(test_text);
    free(input);

    return 0;
}