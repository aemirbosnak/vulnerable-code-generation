//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function to generate the Fibonacci sequence up to a specified number
int* fibonacci(int n) {
    // Allocate memory for the sequence
    int* seq = malloc(n * sizeof(int));

    // Initialize the first two terms of the sequence
    seq[0] = 0;
    seq[1] = 1;

    // Generate the rest of the sequence
    for (int i = 2; i < n; i++) {
        seq[i] = seq[i - 1] + seq[i - 2];
    }

    // Return the sequence
    return seq;
}

// Function to print the Fibonacci sequence
void print_fibonacci(int* seq, int n) {
    // Print each term of the sequence on a new line
    for (int i = 0; i < n; i++) {
        printf("%d\n", seq[i]);
    }
}

// Function to visualize the Fibonacci sequence using ASCII art
void visualize_fibonacci(int* seq, int n) {
    // Print the first term of the sequence
    printf("%d\n", seq[0]);

    // Print the rest of the sequence, with each term indented by one space
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        printf("%d\n", seq[i]);
    }
}

// Main function
int main() {
    // Get the number of terms in the sequence from the user
    int n;
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    // Generate the Fibonacci sequence
    int* seq = fibonacci(n);

    // Print the Fibonacci sequence
    print_fibonacci(seq, n);

    // Visualize the Fibonacci sequence
    visualize_fibonacci(seq, n);

    // Free the memory allocated for the sequence
    free(seq);

    return 0;
}