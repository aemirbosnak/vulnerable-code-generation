//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the function to generate the Fibonacci sequence
int* fibonacci(int n) {
    // Allocate memory for the Fibonacci sequence
    int* fib = malloc(n * sizeof(int));

    // Initialize the first two terms of the sequence
    fib[0] = 0;
    fib[1] = 1;

    // Generate the rest of the sequence
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Return the Fibonacci sequence
    return fib;
}

// Declare the function to print the Fibonacci sequence
void print_fibonacci(int* fib, int n) {
    // Print the Fibonacci sequence
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }

    // Print a newline character
    printf("\n");
}

// Declare the main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the number of terms in the Fibonacci sequence from the user
    int n;
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    // Generate the Fibonacci sequence
    int* fib = fibonacci(n);

    // Print the Fibonacci sequence
    print_fibonacci(fib, n);

    // Free the memory allocated for the Fibonacci sequence
    free(fib);

    // Return 0
    return 0;
}