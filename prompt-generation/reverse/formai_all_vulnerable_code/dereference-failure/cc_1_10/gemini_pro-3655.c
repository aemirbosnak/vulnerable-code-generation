//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: relaxed
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

// Get the user's input and check if it matches the target string
int check_input(char *target, char *input) {
    int len = strlen(target);
    if (len != strlen(input)) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (target[i] != input[i]) {
            return 0;
        }
    }
    return 1;
}

// Print a message to the user
void print_message(char *msg) {
    printf("%s\n", msg);
}

// Get the user's input
char *get_input() {
    char *input = malloc(100);
    scanf("%s", input);
    return input;
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a target string
    char *target = generate_string(10);

    // Print the target string to the user
    print_message("Type the following string as quickly as possible:");
    print_message(target);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char *input = get_input();

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Check if the user's input matches the target string
    int correct = check_input(target, input);

    // Print the results to the user
    if (correct) {
        print_message("Correct!");
    } else {
        print_message("Incorrect.");
    }
    printf("Time taken: %.2f seconds\n", time_taken);

    // Free the allocated memory
    free(target);
    free(input);

    return 0;
}