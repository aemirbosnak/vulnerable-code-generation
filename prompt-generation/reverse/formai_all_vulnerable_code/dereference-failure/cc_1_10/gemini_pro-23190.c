//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random string
char* generate_random_string(int length) {
    char* string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = 65 + rand() % 26;
    }
    string[length] = '\0';
    return string;
}

// Function to test typing speed
void test_typing_speed() {
    // Generate a random string of length 100
    char* string = generate_random_string(100);

    // Print the string
    printf("Type the following string as fast as you can:\n%s\n", string);

    // Start the timer
    clock_t start_time = clock();

    // Get the user's input
    char input[101];
    scanf("%s", input);

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the time taken
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the typing speed in words per minute (WPM)
    double wpm = (double)strlen(string) / 5 / time_taken;

    // Print the results
    printf("You typed %d words per minute.\n", (int)wpm);
}

int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Test the user's typing speed
    test_typing_speed();

    return 0;
}