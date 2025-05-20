//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char *generate_random_string(int n) {
    // Create a buffer to store the string
    char *buffer = malloc(n + 1);
    if (!buffer) {
        return NULL;
    }

    // Generate a random string
    for (int i = 0; i < n; i++) {
        buffer[i] = 'a' + rand() % 26;
    }

    // Terminate the string
    buffer[n] = '\0';

    // Return the string
    return buffer;
}

// Function to calculate the typing speed in words per minute (WPM)
int calculate_typing_speed(int num_words, int time_taken) {
    // Convert time taken from seconds to minutes
    float time_taken_minutes = time_taken / 60.0;

    // Calculate WPM
    int wpm = (num_words / time_taken_minutes);

    // Return WPM
    return wpm;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the length of the string to be typed
    int string_length;
    printf("Enter the length of the string to be typed: ");
    scanf("%d", &string_length);

    // Generate a random string
    char *string = generate_random_string(string_length);

    // Print the string
    printf("Type the following string as quickly and accurately as possible:\n");
    printf("%s\n", string);

    // Start the timer
    clock_t start_time = clock();

    // Get the user's input
    char *user_input = malloc(string_length + 1);
    if (!user_input) {
        return -1;
    }
    scanf("%s", user_input);

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the time taken
    int time_taken = end_time - start_time;

    // Calculate the number of words typed
    int num_words = string_length / 5;

    // Calculate WPM
    int wpm = calculate_typing_speed(num_words, time_taken);

    // Print the typing speed
    printf("Your typing speed is %d WPM.\n", wpm);

    // Free the allocated memory
    free(string);
    free(user_input);

    return 0;
}