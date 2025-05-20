//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n);
void drawGraph(int *fib, int n);

int main() {
    int n;
    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printFibonacci(n);
    return 0;
}

void printFibonacci(int n) {
    int *fib = malloc(n * sizeof(int));
    if (fib == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initializing the first two Fibonacci numbers
    fib[0] = 0;
    if (n > 1) {
        fib[1] = 1;
    }

    printf("\nFibonacci Sequence:\n");
    printf("%d ", fib[0]);
    for (int i = 1; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        printf("%d ", fib[i]);
    }
    printf("\n\n");

    drawGraph(fib, n);

    free(fib);
}

void drawGraph(int *fib, int n) {
    int maxFib = fib[n - 1];

    printf("Graphical Representation:\n");
    for (int i = 0; i < n; i++) {
        int barLength = (fib[i] * 50) / maxFib; // Scale for better visualization
        printf("%3d: ", fib[i]);
        for (int j = 0; j < barLength; j++) {
            printf("*");
        }
        printf("\n");
    }
}