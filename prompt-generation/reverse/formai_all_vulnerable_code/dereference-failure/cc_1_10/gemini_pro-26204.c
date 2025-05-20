//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Get a random character from the given string
char get_random_char(const char *str) {
    return str[rand() % strlen(str)];
}

// Generate a random string of the given length
char *generate_random_string(int length) {
    char *str = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = get_random_char("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    }
    str[length] = '\0';
    return str;
}

// Get the user's input
char *get_user_input() {
    char *input = NULL;
    size_t len = 0;
    getline(&input, &len, stdin);
    return input;
}

// Compare the user's input to the target string
int compare_strings(const char *input, const char *target) {
    int errors = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != target[i]) {
            errors++;
        }
    }
    return errors;
}

// Print the results of the test
void print_results(const char *input, const char *target, int errors, double time_taken) {
    printf("Input: %s\n", input);
    printf("Target: %s\n", target);
    printf("Errors: %d\n", errors);
    printf("Time taken: %.2f seconds\n", time_taken);
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random target string
    const char *target = generate_random_string(100);

    // Get the current time
    clock_t start = clock();

    // Get the user's input
    char *input = get_user_input();

    // Get the current time
    clock_t end = clock();

    // Calculate the time taken
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Compare the user's input to the target string
    int errors = compare_strings(input, target);

    // Print the results of the test
    print_results(input, target, errors, time_taken);

    return 0;
}