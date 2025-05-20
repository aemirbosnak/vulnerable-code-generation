//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string
char *generate_string(int length) {
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = (rand() % 26) + 97;
    }
    string[length] = '\0';
    return string;
}

// Function to check if the user input matches the generated string
int check_input(char *generated_string, char *user_input) {
    return strcmp(generated_string, user_input) == 0;
}

// Recursive function to perform the typing speed test
int typing_speed_test(int length, int seconds) {
    // Generate a random string
    char *generated_string = generate_string(length);

    // Get the current time
    time_t start_time = time(NULL);

    // Prompt the user to type the string
    printf("Type the following string: %s\n", generated_string);

    // Get the user input
    char *user_input = malloc(length + 1);
    scanf("%s", user_input);

    // Get the current time
    time_t end_time = time(NULL);

    // Check if the user input matches the generated string
    int correct = check_input(generated_string, user_input);

    // Calculate the typing speed in words per minute
    int typing_speed = (length / 5) * 60 / (end_time - start_time);

    // Print the results
    printf("Your typing speed is %d words per minute.\n", typing_speed);

    // Free the allocated memory
    free(generated_string);
    free(user_input);

    // If the user input is correct, recursively call the function with increased length and seconds
    if (correct) {
        return typing_speed_test(length + 5, seconds + 1);
    } else {
        return typing_speed;
    }
}

int main() {
    // Set the initial length and seconds for the test
    int length = 50;
    int seconds = 30;

    // Start the typing speed test
    int typing_speed = typing_speed_test(length, seconds);

    // Print the final typing speed
    printf("Your final typing speed is %d words per minute.\n", typing_speed);

    return 0;
}