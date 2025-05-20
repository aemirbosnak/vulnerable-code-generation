//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to generate the Fibonacci sequence and store it in an array
void generateFibonacci(int *fibonacci, int n) {
    if (n >= 1) fibonacci[0] = 0; // First Fibonacci number
    if (n >= 2) fibonacci[1] = 1; // Second Fibonacci number
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}

// Function to visualize the Fibonacci sequence
void visualizeFibonacci(int *fibonacci, int n) {
    printf("\nFibonacci Sequence Visualization:\n");
    printf("=================================\n");
    
    for (int i = 0; i < n; i++) {
        // Change the color based on the Fibonacci number
        if (fibonacci[i] % 2 == 0) {
            printf("\033[1;32m%d\033[0m ", fibonacci[i]); // Green for even
        } else {
            printf("\033[1;34m%d\033[0m ", fibonacci[i]); // Blue for odd
        }
    }
    printf("\n=================================\n");
}

// Function to print a usage message
void printUsage(char *programName) {
    printf("Usage: %s <number_of_terms>\n", programName);
    printf("Example: %s 10\n", programName);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    
    if (n <= 0) {
        printf("Please enter a positive integer greater than zero.\n");
        return EXIT_FAILURE;
    }

    // Allocate memory dynamically for the Fibonacci sequence
    int *fibonacci = (int *)malloc(n * sizeof(int));
    if (fibonacci == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Generate Fibonacci sequence
    generateFibonacci(fibonacci, n);

    // Visualize Fibonacci sequence
    visualizeFibonacci(fibonacci, n);

    // Free allocated memory
    free(fibonacci);

    return EXIT_SUCCESS;
}