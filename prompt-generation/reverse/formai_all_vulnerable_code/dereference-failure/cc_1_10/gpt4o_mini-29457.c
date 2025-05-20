//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Function to generate Fibonacci sequence
void generateFibonacci(int n, unsigned long long *fib) {
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Function to visualize Fibonacci sequence
void visualizeFibonacci(unsigned long long *fib, int n) {
    printf("\nFibonacci Sequence Visualization:\n");
    printf("-----------------------------------\n");

    // Find the maximum value for scaling the visualization
    unsigned long long max = fib[n - 1];
    
    // Print the Fibonacci numbers and their visualization
    for(int i = 0; i < n; i++) {
        printf("%lld: ", fib[i]);
        
        // Calculate the number of asterisks to represent the value
        int numAsterisks = (fib[i] * 50) / (max + 1); // Scale to a max of 50 asterisks
        for(int j = 0; j < numAsterisks; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);
    
    // Handling corner case for n less than 1
    if (n < 1) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    // Allocate memory for Fibonacci numbers
    unsigned long long *fib = (unsigned long long *)malloc(n * sizeof(unsigned long long));
    
    // Check allocation success
    if (fib == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Generate Fibonacci sequence
    generateFibonacci(n, fib);

    // Visualize the sequence
    visualizeFibonacci(fib, n);

    // Free allocated memory
    free(fib);
    
    return 0;
}