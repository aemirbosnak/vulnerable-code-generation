//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string of a given length
char *generate_string(int length) {
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = (char)('a' + rand() % 26);
    }
    string[length] = '\0';
    return string;
}

// Function to test the user's typing speed
void test_typing_speed() {
    // Generate a random string of length 100
    char *string = generate_string(100);

    // Print the string to the console
    printf("Type the following string as quickly as possible:\n\n");
    printf("%s\n\n", string);

    // Start the timer
    clock_t start_time = clock();

    // Wait for the user to finish typing
    char input[101];
    scanf("%s", input);

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the time taken to type the string
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the typing speed in words per minute (WPM)
    double wpm = 60.0 * strlen(string) / (5.0 * time_taken);

    // Print the typing speed to the console
    printf("\nYour typing speed is %.2f WPM.\n", wpm);

    // Free the memory allocated for the string
    free(string);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Test the user's typing speed
    test_typing_speed();

    return 0;
}