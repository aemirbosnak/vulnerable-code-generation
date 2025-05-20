//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Function to generate Fibonacci numbers
void generateFibonacci(int n, unsigned long long *fib) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Function to print the Fibonacci sequence and visualize it
void visualizeFibonacci(int n, unsigned long long *fib) {
    printf("Fibonacci Sequence Visualizer:\n\n");
    for (int i = 0; i < n; i++) {
        // Create a visual representation based on the Fibonacci value
        int numSpaces = fib[i] / (fib[n-1] / 50);  // Scale for visual representation
        printf("%3d: %llu ", i + 1, fib[i]);
        for (int j = 0; j < numSpaces; j++) {
            printf("=");
        }
        printf("\n");
        usleep(200000); // Pause to create a sense of animation
    }
}

int main() {
    int n;

    printf("Enter the number of terms you want in the Fibonacci sequence: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    unsigned long long *fib = (unsigned long long *)malloc(n * sizeof(unsigned long long));
    if (fib == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    generateFibonacci(n, fib);
    visualizeFibonacci(n, fib);

    // Free allocated memory
    free(fib);
    return 0;
}