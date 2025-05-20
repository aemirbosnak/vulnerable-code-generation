//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Function to print the Fibonacci sequence
void printFibonacci(int n) {
    long long *fibonacci = (long long *)malloc(n * sizeof(long long));
    if (fibonacci == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    // Initialize the first two Fibonacci numbers
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    printf("Fibonacci Sequence Visualization:\n");
    printf("-----------------------------------\n");
    printf("| Index | Fibonacci |  Square  |\n");
    printf("-----------------------------------\n");
    
    // Print the first two Fibonacci numbers
    printf("| %5d | %10lld | %8lld |\n", 0, fibonacci[0], fibonacci[0] * fibonacci[0]);
    printf("| %5d | %10lld | %8lld |\n", 1, fibonacci[1], fibonacci[1] * fibonacci[1]);

    // Calculate the Fibonacci sequence iteratively
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        printf("| %5d | %10lld | %8lld |\n", i, fibonacci[i], fibonacci[i] * fibonacci[i]);
    }
    printf("-----------------------------------\n");
    
    // Free allocated memory
    free(fibonacci);
}

// Function to get user input
int getUserInput() {
    int n;
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);
   
    // Validate input
    while (n < 1) {
        printf("Please enter a positive integer: ");
        scanf("%d", &n);
    }
    return n;
}

int main() {
    int n = getUserInput();
    printFibonacci(n);
    return 0;
}