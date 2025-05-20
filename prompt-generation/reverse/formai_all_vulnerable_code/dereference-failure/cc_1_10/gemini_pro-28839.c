//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Structure to store the Fibonacci sequence
struct FibonacciSequence {
    int *sequence;
    int length;
};

// Function to initialize the Fibonacci sequence
struct FibonacciSequence *initializeFibonacciSequence(int length) {
    struct FibonacciSequence *sequence = malloc(sizeof(struct FibonacciSequence));
    sequence->length = length;
    sequence->sequence = malloc(sizeof(int) * length);

    // Initialize the first two terms of the sequence
    sequence->sequence[0] = 0;
    sequence->sequence[1] = 1;

    // Calculate the remaining terms of the sequence
    for (int i = 2; i < length; i++) {
        sequence->sequence[i] = sequence->sequence[i - 1] + sequence->sequence[i - 2];
    }

    return sequence;
}

// Function to print the Fibonacci sequence
void printFibonacciSequence(struct FibonacciSequence *sequence) {
    printf("Fibonacci Sequence: ");
    for (int i = 0; i < sequence->length; i++) {
        printf("%d ", sequence->sequence[i]);
    }
    printf("\n");
}

// Function to visualize the Fibonacci sequence using ASCII art
void visualizeFibonacciSequence(struct FibonacciSequence *sequence) {
    // Calculate the maximum number of digits in the sequence
    int maxDigits = 0;
    for (int i = 0; i < sequence->length; i++) {
        int numDigits = 0;
        int temp = sequence->sequence[i];
        while (temp > 0) {
            numDigits++;
            temp /= 10;
        }
        if (numDigits > maxDigits) {
            maxDigits = numDigits;
        }
    }

    // Print the header
    printf("Fibonacci Sequence Visualization:\n");
    printf("  ");
    for (int i = 0; i < sequence->length; i++) {
        for (int j = 0; j < maxDigits; j++) {
            printf("-");
        }
        printf(" ");
    }
    printf("\n");

    // Print the sequence
    printf("  ");
    for (int i = 0; i < sequence->length; i++) {
        int numSpaces = maxDigits - (int)log10(sequence->sequence[i]);
        for (int j = 0; j < numSpaces; j++) {
            printf(" ");
        }
        printf("%d ", sequence->sequence[i]);
    }
    printf("\n");

    // Print the footer
    printf("  ");
    for (int i = 0; i < sequence->length; i++) {
        for (int j = 0; j < maxDigits; j++) {
            printf("-");
        }
        printf(" ");
    }
    printf("\n");
}

// Main function
int main() {
    // Initialize the Fibonacci sequence
    struct FibonacciSequence *sequence = initializeFibonacciSequence(10);

    // Print the Fibonacci sequence
    printFibonacciSequence(sequence);

    // Visualize the Fibonacci sequence
    visualizeFibonacciSequence(sequence);

    // Free the memory allocated for the sequence
    free(sequence->sequence);
    free(sequence);

    return 0;
}