//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mathematical
#include <stdio.h>

void printFibonacci(int n);
void drawVisualization(int value, int maxValue);

int main() {
    int n;

    printf("Enter the number of Fibonacci terms to visualize: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printf("\nFibonacci Sequence Visualization:\n");
    printFibonacci(n);

    return 0;
}

void printFibonacci(int n) {
    long long int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    // Calculating Fibonacci numbers and storing in an array
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Find the maximum Fibonacci number for scaling purpose
    long long int maxValue = fib[n - 1];

    for (int i = 0; i < n; i++) {
        printf("F(%d) = %lld: ", i, fib[i]);
        drawVisualization(fib[i], maxValue);
        printf("\n");
    }
}

void drawVisualization(int value, int maxValue) {
    // Scale the drawn value proportional to the maximum Fibonacci number
    int scale = (value * 70) / maxValue; // Scale to a maximum of 70 characters

    // Print visualization using asterisks
    for (int j = 0; j < scale; j++) {
        putchar('*');
    }
    for (int j = scale; j < 70; j++) {
        putchar(' ');
    }
}