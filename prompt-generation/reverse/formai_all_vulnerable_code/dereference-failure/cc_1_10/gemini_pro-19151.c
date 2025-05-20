//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to hold a Fibonacci number and its position in the sequence
typedef struct {
    int number;
    int position;
} Fibonacci;

// Function to generate the Fibonacci sequence up to a specified number of terms
Fibonacci* generateFibonacciSequence(int numTerms) {
    Fibonacci* sequence = (Fibonacci*)malloc(sizeof(Fibonacci) * numTerms);

    // Initialize the first two terms of the sequence
    sequence[0].number = 0;
    sequence[0].position = 0;
    sequence[1].number = 1;
    sequence[1].position = 1;

    // Generate the remaining terms of the sequence
    for (int i = 2; i < numTerms; i++) {
        sequence[i].number = sequence[i - 1].number + sequence[i - 2].number;
        sequence[i].position = i;
    }

    return sequence;
}

// Function to print the Fibonacci sequence in a visually appealing way
void printFibonacciSequence(Fibonacci* sequence, int numTerms) {
    // Find the maximum number of digits in the sequence
    int maxDigits = 0;
    for (int i = 0; i < numTerms; i++) {
        int numDigits = (int)log10(sequence[i].number) + 1;
        if (numDigits > maxDigits) {
            maxDigits = numDigits;
        }
    }

    // Print the sequence in a table format
    printf("+---------+-------------------+\n");
    printf("| Position | Fibonacci Number |\n");
    printf("+---------+-------------------+\n");
    for (int i = 0; i < numTerms; i++) {
        printf("| %7d | %*d |\n", sequence[i].position, maxDigits, sequence[i].number);
    }
    printf("+---------+-------------------+\n");
}

int main() {
    // Generate the Fibonacci sequence
    int numTerms = 10;
    Fibonacci* sequence = generateFibonacciSequence(numTerms);

    // Print the Fibonacci sequence
    printFibonacciSequence(sequence, numTerms);

    // Free the memory allocated for the sequence
    free(sequence);

    return 0;
}