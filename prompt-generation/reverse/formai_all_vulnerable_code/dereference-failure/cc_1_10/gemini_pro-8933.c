//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum length of the input text
#define MAX_TEXT_LENGTH 1000

// Function to generate a random string of characters
char *generate_random_text(int length) {
    // Allocate memory for the string
    char *text = malloc(length + 1);

    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random string of characters
    for (int i = 0; i < length; i++) {
        text[i] = 'a' + rand() % 26;
    }

    // Terminate the string with a null character
    text[length] = '\0';

    // Return the string
    return text;
}

// Function to test the user's typing speed
int test_typing_speed(char *text) {
    // Print the text to the console
    printf("%s\n", text);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char input[MAX_TEXT_LENGTH];
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time it took the user to type the text
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the user's typing speed in words per minute (WPM)
    int wpm = (int)((strlen(text) / 5) / time_taken);

    // Return the user's typing speed
    return wpm;
}

// Main function
int main() {
    // Generate a random string of characters
    char *text = generate_random_text(MAX_TEXT_LENGTH);

    // Test the user's typing speed
    int wpm = test_typing_speed(text);

    // Print the user's typing speed to the console
    printf("Your typing speed is %d WPM.\n", wpm);

    // Free the memory allocated for the text
    free(text);

    return 0;
}