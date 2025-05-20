//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the Fibonacci sequence
#define MAX_SEQUENCE_SIZE 50

// Function to generate the Fibonacci sequence
int* generateFibonacci(int size) {
    if (size > MAX_SEQUENCE_SIZE || size <= 0) {
        printf("Invalid sequence size!\n");
        return NULL;
    }

    // Allocate memory for the sequence
    int* sequence = (int*)malloc(size * sizeof(int));

    // Generate the sequence
    sequence[0] = 0;
    sequence[1] = 1;
    for (int i = 2; i < size; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }

    return sequence;
}

// Function to display the Fibonacci sequence
void displayFibonacci(int* sequence, int size) {
    printf("Fibonacci sequence:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Get the size of the sequence from the user
    int size;
    printf("Enter the size of the Fibonacci sequence (up to %d): ", MAX_SEQUENCE_SIZE);
    scanf("%d", &size);

    // Generate and display the sequence
    int* sequence = generateFibonacci(size);
    if (sequence != NULL) {
        displayFibonacci(sequence, size);
    }

    // Free memory allocated by the sequence
    free(sequence);

    return 0;
}