//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char *generate_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to test typing speed
int test_typing_speed() {
    // Generate a random string of length 100
    char *str = generate_string(100);

    // Start the timer
    clock_t start = clock();

    // Prompt the user to type the string
    printf("Type the following string as fast as you can:\n%s\n", str);

    // Get the user's input
    char *input = malloc(101);
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the typing speed in words per minute (WPM)
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    int wpm = (int)((strlen(str) / 5) / time_taken * 60);

    // Free the allocated memory
    free(str);
    free(input);

    // Return the typing speed
    return wpm;
}

int main() {
    // Test the typing speed
    int wpm = test_typing_speed();

    // Print the typing speed
    printf("Your typing speed is: %d WPM\n", wpm);

    return 0;
}