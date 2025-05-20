//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: invasive
#include <stdio.h>
#include <math.h>

// Function to calculate the nth Fibonacci number
unsigned long long int fibonacci(unsigned int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to print the Fibonacci series up to the nth term
void printFibonacci(unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        printf("%llu ", fibonacci(i));
    }
    printf("\n");
}

// Function to generate a visual representation of the Fibonacci series
// using ASCII characters
void visualizeFibonacci(unsigned int n) {
    // Calculate the maximum number of digits in the Fibonacci series up to the nth term
    unsigned int maxDigits = floor(log10(fibonacci(n))) + 1;

    // Allocate memory for the visual representation
    char *visualization = malloc((n + 1) * maxDigits * sizeof(char));

    // Initialize the visualization with spaces
    for (unsigned int i = 0; i < (n + 1) * maxDigits; i++) {
        visualization[i] = ' ';
    }

    // Fill the visualization with the Fibonacci numbers
    for (unsigned int i = 0; i < n; i++) {
        unsigned long long int fibonacciNumber = fibonacci(i);
        unsigned int numDigits = floor(log10(fibonacciNumber)) + 1;
        for (unsigned int j = 0; j < numDigits; j++) {
            visualization[(i + 1) * maxDigits - j - 1] = '0' + fibonacciNumber % 10;
            fibonacciNumber /= 10;
        }
    }

    // Print the visualization
    for (unsigned int i = 0; i < n + 1; i++) {
        for (unsigned int j = 0; j < maxDigits; j++) {
            printf("%c", visualization[i * maxDigits + j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    free(visualization);
}

// Main function
int main() {
    unsigned int n;
    printf("Enter the number of terms in the Fibonacci series to visualize: ");
    scanf("%u", &n);

    visualizeFibonacci(n);

    return 0;
}