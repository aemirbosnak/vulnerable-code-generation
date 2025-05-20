//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate a random string of length 'len'
char *generate_string(int len) {
    char *str = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[len] = '\0';
    return str;
}

// Compare two strings and return the number of errors
int compare_strings(char *str1, char *str2) {
    int errors = 0;
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            errors++;
        }
    }
    return errors;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random string of length 100
    char *str = generate_string(100);

    // Print the string to the user
    printf("Type the following string as accurately and quickly as possible:\n\n%s\n\n", str);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char *input = malloc(101);
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the elapsed time in seconds
    double time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the typing speed in words per minute (WPM)
    int wpm = (int)((100 / time_elapsed) * 60);

    // Calculate the error rate
    int errors = compare_strings(str, input);
    double error_rate = (double)errors / 100;

    // Print the results
    printf("\nTime elapsed: %.2f seconds\n", time_elapsed);
    printf("Typing speed: %d WPM\n", wpm);
    printf("Error rate: %.2f%%\n", error_rate * 100);

    // Free the allocated memory
    free(str);
    free(input);

    return 0;
}