//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the fortunes
char *fortunes[] = {
    "You will have a great day!",
    "You will meet someone special.",
    "You will get a promotion at work.",
    "You will win the lottery.",
    "You will find true love.",
    "You will have a long and happy life.",
    "You will achieve all your goals.",
    "You will be successful in everything you do.",
    "You will be loved by everyone you meet.",
    "You will be happy and content."
};

// Get a random fortune
char *get_fortune() {
    // Seed the random number generator
    srand(time(NULL));

    // Get a random number between 0 and the number of fortunes
    int random_number = rand() % (sizeof(fortunes) / sizeof(char *));

    // Return the fortune at the random index
    return fortunes[random_number];
}

// Print the fortune
void print_fortune(char *fortune) {
    printf("Your fortune is: %s\n", fortune);
}

// Get the user's input
char *get_input() {
    // Allocate memory for the input
    char *input = malloc(1024);

    // Get the input from the user
    printf("Enter your question: ");
    fgets(input, 1024, stdin);

    // Remove the newline character from the input
    input[strlen(input) - 1] = '\0';

    // Return the input
    return input;
}

// Main function
int main() {
    // Get the user's input
    char *input = get_input();

    // Get a random fortune
    char *fortune = get_fortune();

    // Print the fortune
    print_fortune(fortune);

    // Free the allocated memory
    free(input);

    return 0;
}