//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the Fibonacci sequence
void generateFibonacci(int n, int* fib) {
    fib[0] = 0; // First Fibonacci number
    fib[1] = 1; // Second Fibonacci number

    for(int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2]; // Calculate next Fibonacci number
    }
}

// Function to display the Fibonacci sequence in a happy way
void displayFibonacci(int n, int* fib) {
    printf("🎉🎊 Welcome to the Fibonacci Sequence Visualizer! 🎊🎉\n\n");
    printf("Here are the first %d Fibonacci numbers:\n\n", n);
    
    for(int i = 0; i < n; i++) {
        printf("Fibonacci[%d]: %d\n", i, fib[i]);
    }

    printf("\nLet's visualize the Fibonacci sequence in a colorful manner! 🌈\n\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < fib[i]; j++) {
            printf("🌼"); // Each Fibonacci number is represented with flowers
        }
        printf(" (%d) \n", fib[i]);
    }

    printf("\n🌟 Thank you for using the Fibonacci Sequence Visualizer! 🌟\n");
    printf("Have a wonderful day ahead! 😊\n");
}

// Main function
int main() {
    int n;

    printf("Enter how many Fibonacci numbers you want to see (e.g., 10): ");
    scanf("%d", &n);

    // Input validation
    if(n <= 0) {
        printf("Oh no! Please enter a positive integer greater than 0! 🌟\n");
        return 1;
    }

    // Allocate memory for Fibonacci numbers
    int* fib = (int*) malloc(n * sizeof(int));
    if(fib == NULL) {
        printf("Oops! Memory allocation failed! 😢\n");
        return 1;
    }

    // Generating the Fibonacci sequence
    generateFibonacci(n, fib);

    // Displaying the Fibonacci sequence
    displayFibonacci(n, fib);

    // Freeing allocated memory
    free(fib);

    return 0;
}