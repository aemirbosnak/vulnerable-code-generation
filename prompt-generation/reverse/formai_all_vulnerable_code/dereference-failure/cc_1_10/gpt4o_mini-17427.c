//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void displayFibonacci(int n) {
    int *fib = (int *)malloc(n * sizeof(int));
    if (fib == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
 
    // Initialize the first two Fibonacci numbers
    fib[0] = 0;
    fib[1] = 1;
    
    printf("Fibonacci Sequence:\n");
    printf("Index\tValue\n");
    printf("0\t%d\n", fib[0]);
    printf("1\t%d\n", fib[1]);
    
    // Compute the Fibonacci sequence up to n terms
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        printf("%d\t%d\n", i, fib[i]);
    }

    // Visualize the Fibonacci sequence using ASCII bars
    printf("\nFibonacci Visualization:\n");
    for (int i = 0; i < n; i++) {
        printf("%d | ", fib[i]);
        for (int j = 0; j < fib[i] / 2; j++) { // Scale down for visualization
            printf("#");
        }
        printf("\n");
    }

    free(fib); // Clean up allocated memory
}

int main() {
    int n;
    
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of Fibonacci terms to display (e.g., 10): ");
    scanf("%d", &n);
    
    if (n < 1) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }
    
    displayFibonacci(n);
    
    return 0;
}