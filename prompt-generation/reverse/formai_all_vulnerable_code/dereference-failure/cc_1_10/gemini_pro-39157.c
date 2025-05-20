//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string of length 'len'
char *generate_random_string(int len) {
    char *str = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        // Generate a random character between 'a' and 'z'
        char c = 'a' + (rand() % 26);
        str[i] = c;
    }
    str[len] = '\0';
    return str;
}

// Function to get the user's input string
char *get_user_input(int len) {
    char *str = malloc(len + 1);
    printf("Type the following string as fast as you can: ");
    scanf("%s", str);
    return str;
}

// Function to calculate the typing speed
float calculate_typing_speed(char *target, char *user_input, int len) {
    // Calculate the number of correctly typed characters
    int correct_chars = 0;
    for (int i = 0; i < len; i++) {
        if (target[i] == user_input[i]) {
            correct_chars++;
        }
    }

    // Calculate the typing speed in words per minute (WPM)
    float wpm = (float)correct_chars / 5.0;

    return wpm;
}

// Function to print the results
void print_results(float wpm) {
    printf("\nYour typing speed is: %.2f WPM\n", wpm);
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random string of length 100
    int len = 100;
    char *target = generate_random_string(len);

    // Get the user's input string
    char *user_input = get_user_input(len);

    // Calculate the typing speed
    float wpm = calculate_typing_speed(target, user_input, len);

    // Print the results
    print_results(wpm);

    // Free the allocated memory
    free(target);
    free(user_input);

    return 0;
}