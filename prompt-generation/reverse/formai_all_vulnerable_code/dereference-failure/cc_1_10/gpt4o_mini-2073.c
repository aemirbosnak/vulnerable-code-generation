//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: systematic
#include <stdio.h>

// Function to calculate Fibonacci numbers
void generateFibonacci(int limit, int *fibonacciArray) {
    fibonacciArray[0] = 0;   // First Fibonacci number
    fibonacciArray[1] = 1;   // Second Fibonacci number
    for (int i = 2; i < limit; i++) {
        fibonacciArray[i] = fibonacciArray[i - 1] + fibonacciArray[i - 2]; // Calculate the next Fibonacci number
    }
}

// Function to visualize the Fibonacci sequence
void visualizeFibonacci(int *fibonacciArray, int limit) {
    printf("\nFibonacci Sequence Visualization:\n\n");
    for (int i = 0; i < limit; i++) {
        // Print the Fibonacci number
        printf("%d: %d\t", i + 1, fibonacciArray[i]);
        
        // Visualize the Fibonacci number with asterisks
        for (int j = 0; j < fibonacciArray[i]; j++) {
            printf("*");
        }
        printf("\n"); // New line after each representation
    }
}

int main() {
    int limit;

    // User input for limit
    printf("Enter the number of terms in the Fibonacci sequence to visualize: ");
    scanf("%d", &limit);

    // Limit validation
    if (limit <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    // Array to hold Fibonacci numbers
    int fibonacciArray[limit];

    // Generate the Fibonacci sequence
    generateFibonacci(limit, fibonacciArray);

    // Visualize the Fibonacci sequence
    visualizeFibonacci(fibonacciArray, limit);

    return 0;
}