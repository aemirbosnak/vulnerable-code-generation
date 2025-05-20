//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Generate a random string of length n
char *generate_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Get the current time in milliseconds
long long get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000LL + ts.tv_nsec / 1000000LL;
}

int main() {
    // Set the length of the string to be typed
    int n = 100;

    // Generate a random string
    char *str = generate_string(n);

    // Print the string to the console
    printf("Type the following string as quickly as possible:\n\n");
    printf("%s\n\n", str);

    // Start the timer
    long long start_time = get_time();

    // Get the user's input
    char *input = malloc(n + 1);
    scanf("%s", input);

    // Stop the timer
    long long end_time = get_time();

    // Check if the user's input matches the original string
    int correct = strcmp(input, str) == 0;

    // Calculate the time taken to type the string
    long long time_taken = end_time - start_time;

    // Calculate the typing speed in words per minute (WPM)
    int wpm = (n / 5) * 60000 / time_taken;

    // Print the results
    printf("\n\nResults:\n");
    printf("Correct: %s\n", correct ? "Yes" : "No");
    printf("Time taken: %lld ms\n", time_taken);
    printf("Typing speed: %d WPM\n", wpm);

    return 0;
}