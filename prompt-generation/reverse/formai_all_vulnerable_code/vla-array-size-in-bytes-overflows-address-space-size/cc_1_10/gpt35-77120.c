//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>

int fibonacci(int n);
void visualize(int n);

int main() {
    int n;
    printf("Enter the number of terms in the Fibonacci sequence to visualize: ");
    scanf("%d", &n);
    printf("\nHere's a paranoid visualization of the first %d terms of the Fibonacci sequence:\n\n", n);
    visualize(n);

    return 0;
}

// Recursive function to generate the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to visualize a paranoid representation of the Fibonacci sequence
void visualize(int n) {
    int a[n];
    int i, j;
    int max_val = fibonacci(n);
    int digit_count = 0;
    int num_spaces = 0;
    int num_stars = 0;

    // Calculate number of digits in largest Fibonacci number
    while (max_val > 0) {
        max_val /= 10;
        digit_count++;
    }

    // Fill array with Fibonacci numbers
    for (i = 0; i < n; i++) {
        a[i] = fibonacci(i);
    }

    // Visualize each Fibonacci number
    for (i = 0; i < n; i++) {
        printf("%d:", a[i]);

        // Calculate number of spaces and stars needed for paranoid visualization
        num_spaces = digit_count - 1 - i;
        num_stars = a[i] % 5 + 1;

        // Output paranoid visualization
        for (j = 0; j < num_spaces; j++) {
            printf(" ");
        }
        for (j = 0; j < num_stars; j++) {
            printf("*");
        }
        printf("\n");
    }
}