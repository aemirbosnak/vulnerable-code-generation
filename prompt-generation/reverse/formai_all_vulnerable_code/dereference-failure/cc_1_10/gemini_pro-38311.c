//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate the Fibonacci sequence
int* fibonacci(int n) {
    int* fib = malloc(n * sizeof(int));
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib;
}

// Function to print the Fibonacci sequence
void print_fibonacci(int* fib, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
}

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random Fibonacci sequence
int* random_fibonacci(int n) {
    int* fib = malloc(n * sizeof(int));
    fib[0] = random_number(0, 100);
    fib[1] = random_number(0, 100);
    for (int i = 2; i < n; i++) {
        fib[i] = random_number(fib[i - 1], fib[i - 2]);
    }
    return fib;
}

// Function to visualize the Fibonacci sequence
void visualize_fibonacci(int* fib, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < fib[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random Fibonacci sequence of length 10
    int n = 10;
    int* fib = random_fibonacci(n);

    // Print the Fibonacci sequence
    print_fibonacci(fib, n);

    // Visualize the Fibonacci sequence
    visualize_fibonacci(fib, n);

    // Free the allocated memory
    free(fib);

    return 0;
}