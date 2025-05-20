//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: systematic
#include <stdio.h>

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to print the first n Fibonacci numbers
void printFibonacci(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
}

// Function to visualize the Fibonacci sequence using ASCII art
void visualizeFibonacci(int n) {
    // Create an array to store the Fibonacci numbers
    int fib[n];

    // Calculate the first n Fibonacci numbers
    for (int i = 0; i < n; i++) {
        fib[i] = fibonacci(i);
    }

    // Create a 2D array to store the ASCII art representation of the Fibonacci sequence
    char art[n][n];

    // Initialize the ASCII art array with spaces
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            art[i][j] = ' ';
        }
    }

    // Draw the Fibonacci sequence in the ASCII art array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < fib[i]; j++) {
            art[i][j] = '*';
        }
    }

    // Print the ASCII art representation of the Fibonacci sequence
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Get the number of Fibonacci numbers to print
    int n;
    printf("Enter the number of Fibonacci numbers to print: ");
    scanf("%d", &n);

    // Print the first n Fibonacci numbers
    printf("The first %d Fibonacci numbers are: ", n);
    printFibonacci(n);
    printf("\n");

    // Visualize the Fibonacci sequence using ASCII art
    printf("ASCII art representation of the Fibonacci sequence:\n");
    visualizeFibonacci(n);

    return 0;
}