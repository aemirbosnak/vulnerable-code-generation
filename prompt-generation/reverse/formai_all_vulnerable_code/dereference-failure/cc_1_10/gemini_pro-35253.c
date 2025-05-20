//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of characters
char *generate_string(int length) {
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = 'a' + rand() % 26;
    }
    string[length] = '\0';
    return string;
}

// Function to compare two strings and return the number of errors
int compare_strings(char *string1, char *string2) {
    int errors = 0;
    for (int i = 0; i < strlen(string1); i++) {
        if (string1[i] != string2[i]) {
            errors++;
        }
    }
    return errors;
}

// Function to run the typing speed test
void run_test() {
    // Generate a random string of characters
    char *string = generate_string(100);

    // Display the string to the user
    printf("Type the following string as accurately and quickly as possible:\n\n");
    printf("%s\n\n", string);

    // Start the timer
    clock_t start_time = clock();

    // Get the user's input
    char *input = malloc(101);
    scanf("%s", input);

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the time taken
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the number of errors
    int errors = compare_strings(string, input);

    // Calculate the typing speed
    double speed = (double)(strlen(string) - errors) / time_taken;

    // Display the results
    printf("\nTime taken: %.2f seconds\n", time_taken);
    printf("Errors: %d\n", errors);
    printf("Typing speed: %.2f words per minute\n", speed * 60 / 5);

    // Free the allocated memory
    free(string);
    free(input);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Run the typing speed test
    run_test();

    return 0;
}