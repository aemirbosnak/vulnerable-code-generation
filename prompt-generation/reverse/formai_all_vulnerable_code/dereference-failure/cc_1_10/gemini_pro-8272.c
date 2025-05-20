//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char* generate_string(int n) {
    char* str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to compare two strings and return the number of errors
int compare_strings(char* str1, char* str2) {
    int errors = 0;
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            errors++;
        }
    }
    return errors;
}

// Function to start the typing test
void start_test() {
    // Generate a random string of length 100
    char* str = generate_string(100);

    // Print the string to the screen
    printf("Type the following string as quickly and accurately as possible:\n\n%s\n\n", str);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char* input = malloc(101);
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the number of errors
    int errors = compare_strings(str, input);

    // Calculate the typing speed
    double speed = 100 / time_taken;

    // Print the results
    printf("\nResults:\n\nTime taken: %.2f seconds\nErrors: %d\nSpeed: %.2f WPM\n", time_taken, errors, speed);

    // Free the allocated memory
    free(str);
    free(input);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Start the typing test
    start_test();

    return 0;
}