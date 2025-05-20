//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of a given length
char *generate_random_string(size_t length) {
    char *string = malloc(length + 1);
    for (size_t i = 0; i < length; i++) {
        string[i] = (char) (rand() % 26 + 97);
    }
    string[length] = '\0';
    return string;
}

// Function to calculate the typing speed in words per minute (WPM)
double calculate_wpm(size_t correct_characters, double time_seconds) {
    return (correct_characters / 5) / (time_seconds / 60);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random string of length 100
    char *target_string = generate_random_string(100);

    // Print the target string to the console
    printf("Type the following string as quickly and accurately as possible:\n");
    printf("%s\n", target_string);

    // Start the timer
    clock_t start_time = clock();

    // Get the user's input
    char *user_input = malloc(101);
    scanf("%s", user_input);

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the time taken to type the string
    double time_seconds = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the number of correct characters typed
    size_t correct_characters = 0;
    for (size_t i = 0; i < 100; i++) {
        if (user_input[i] == target_string[i]) {
            correct_characters++;
        }
    }

    // Calculate the typing speed in WPM
    double wpm = calculate_wpm(correct_characters, time_seconds);

    // Print the results to the console
    printf("Your typing speed is %.2f WPM.\n", wpm);

    // Free the allocated memory
    free(target_string);
    free(user_input);

    return 0;
}