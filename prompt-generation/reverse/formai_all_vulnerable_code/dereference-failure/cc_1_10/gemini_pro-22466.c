//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Macros for colors
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

// Function to generate a random string
char *generate_random_string(int length) {
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = (rand() % 26) + 'a';
    }
    string[length] = '\0';
    return string;
}

// Function to get the user's input
char *get_user_input(int length) {
    char *input = malloc(length + 1);
    fgets(input, length + 1, stdin);
    return input;
}

// Function to compare the user's input to the target string
int compare_strings(char *input, char *target) {
    int correct = 0;
    for (int i = 0; i < strlen(target); i++) {
        if (input[i] == target[i]) {
            correct++;
        }
    }
    return correct;
}

// Function to print the results of the test
void print_results(int correct, int total) {
    float accuracy = (float)correct / total * 100;
    printf("Your accuracy is: %.2f%%\n", accuracy);
    if (accuracy >= 90) {
        printf("Congratulations! You're a typing master!\n");
    } else if (accuracy >= 80) {
        printf("You're a pretty good typer!\n");
    } else if (accuracy >= 70) {
        printf("You're getting there!\n");
    } else {
        printf("You need to practice more!\n");
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random string
    char *target = generate_random_string(10);

    // Get the user's input
    char *input = get_user_input(10);

    // Compare the user's input to the target string
    int correct = compare_strings(input, target);

    // Print the results of the test
    print_results(correct, 10);

    // Free the allocated memory
    free(target);
    free(input);

    return 0;
}