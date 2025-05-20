//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MAX_ATTEMPTS 5

// Function to check if the input is valid
int is_valid_input(char *input) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i]) && input[i] != '.') {
            return 0;
        }
    }
    return 1;
}

// Function to perform the actual calculation
double calculate(char *input) {
    double result = 0;
    int i, j;
    char op;

    // Parse the input and extract the operator and operands
    if (sscanf(input, "%d%c%d", &i, &op, &j) != 3) {
        return 0;
    }

    // Perform the calculation
    switch (op) {
        case '+':
            result = i + j;
            break;
        case '-':
            result = i - j;
            break;
        case '*':
            result = i * j;
            break;
        case '/':
            result = i / j;
            break;
        default:
            return 0;
    }

    return result;
}

int main() {
    char input[MAX_LENGTH];
    int attempts = 0;

    // Loop until the user enters a valid input
    while (1) {
        // Ask the user for input
        printf("Enter a mathematical expression (e.g. 2+2): ");
        fgets(input, MAX_LENGTH, stdin);

        // Check if the input is valid
        if (is_valid_input(input)) {
            // Perform the calculation
            double result = calculate(input);

            // Print the result
            printf("Result: %f\n", result);
            break;
        }

        // If the input is not valid, try again
        attempts++;
        if (attempts >= MAX_ATTEMPTS) {
            printf("Too many attempts! Giving up...\n");
            break;
        }
        printf("Invalid input. Please try again...\n");
    }

    return 0;
}