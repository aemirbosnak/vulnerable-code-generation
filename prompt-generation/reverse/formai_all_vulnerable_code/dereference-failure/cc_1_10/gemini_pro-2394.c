//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of Fibonacci numbers to generate
#define MAX_FIB 100

// Define the color codes for the different Fibonacci numbers
#define COLOR_0 "\x1b[31m"  // Red
#define COLOR_1 "\x1b[32m"  // Green
#define COLOR_2 "\x1b[33m"  // Yellow
#define COLOR_3 "\x1b[34m"  // Blue
#define COLOR_4 "\x1b[35m"  // Magenta
#define COLOR_5 "\x1b[36m"  // Cyan
#define COLOR_6 "\x1b[37m"  // White
#define COLOR_7 "\x1b[0m"   // Reset

// Define the function to generate the Fibonacci sequence
int *generate_fibonacci(int n) {
    int *fib = malloc(n * sizeof(int));
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib;
}

// Define the function to print the Fibonacci sequence
void print_fibonacci(int *fib, int n) {
    for (int i = 0; i < n; i++) {
        switch (i) {
            case 0:
                printf("%s%d%s", COLOR_0, fib[i], COLOR_7);
                break;
            case 1:
                printf("%s%d%s", COLOR_1, fib[i], COLOR_7);
                break;
            case 2:
                printf("%s%d%s", COLOR_2, fib[i], COLOR_7);
                break;
            case 3:
                printf("%s%d%s", COLOR_3, fib[i], COLOR_7);
                break;
            case 4:
                printf("%s%d%s", COLOR_4, fib[i], COLOR_7);
                break;
            case 5:
                printf("%s%d%s", COLOR_5, fib[i], COLOR_7);
                break;
            case 6:
                printf("%s%d%s", COLOR_6, fib[i], COLOR_7);
                break;
            default:
                printf("%d", fib[i]);
                break;
        }
        printf(" ");
    }
    printf("\n");
}

// Define the main function
int main() {
    // Generate the Fibonacci sequence
    int *fib = generate_fibonacci(MAX_FIB);

    // Print the Fibonacci sequence
    print_fibonacci(fib, MAX_FIB);

    // Free the allocated memory
    free(fib);

    return 0;
}