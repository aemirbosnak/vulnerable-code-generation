//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string of length n
char* generate_random_string(int n) {
    char* str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    str[n] = '\0';
    return str;
}

// Function to compare two strings and return the number of errors
int compare_strings(char* str1, char* str2) {
    int errors = 0;
    for (int i = 0; i < strlen(str1); i++) {
        if (str1[i] != str2[i]) {
            errors++;
        }
    }
    return errors;
}

// Function to run the typing speed test
void run_typing_speed_test() {
    // Generate a random string of length 100
    char* target_string = generate_random_string(100);

    // Print the target string to the console
    printf("Target string: %s\n", target_string);

    // Get the current time
    clock_t start_time = clock();

    // Get the user's input
    char* user_input = malloc(101);
    scanf("%s", user_input);

    // Get the current time
    clock_t end_time = clock();

    // Calculate the elapsed time
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the typing speed
    double typing_speed = (double)strlen(target_string) / elapsed_time;

    // Calculate the number of errors
    int errors = compare_strings(target_string, user_input);

    // Print the results
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    printf("Typing speed: %.2f words per minute\n", typing_speed);
    printf("Errors: %d\n", errors);

    // Free the allocated memory
    free(target_string);
    free(user_input);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Run the typing speed test
    run_typing_speed_test();

    return 0;
}