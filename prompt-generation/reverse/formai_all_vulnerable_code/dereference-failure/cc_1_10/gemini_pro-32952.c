//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of Fibonacci numbers to generate
#define MAX_FIB 100

// Define the colors for the Fibonacci sequence
#define COLOR_0 "\033[31m" // Red
#define COLOR_1 "\033[32m" // Green
#define COLOR_2 "\033[33m" // Yellow
#define COLOR_3 "\033[34m" // Blue
#define COLOR_4 "\033[35m" // Magenta
#define COLOR_5 "\033[36m" // Cyan
#define COLOR_6 "\033[37m" // White
#define COLOR_7 "\033[38m" // Gray

// Define the color reset code
#define COLOR_RESET "\033[0m"

// Generate a random color for the given Fibonacci number
char *get_color(int fib)
{
    switch (fib % 7)
    {
    case 0:
        return COLOR_0;
    case 1:
        return COLOR_1;
    case 2:
        return COLOR_2;
    case 3:
        return COLOR_3;
    case 4:
        return COLOR_4;
    case 5:
        return COLOR_5;
    case 6:
        return COLOR_6;
    default:
        return COLOR_7;
    }
}

// Generate the Fibonacci sequence
int *generate_fibonacci(int max)
{
    int *fib = malloc(sizeof(int) * max);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < max; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib;
}

// Print the Fibonacci sequence with colors
void print_fibonacci(int *fib, int max)
{
    for (int i = 0; i < max; i++)
    {
        printf("%s%d ", get_color(i), fib[i]);
    }
    printf(COLOR_RESET "\n");
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Generate the Fibonacci sequence
    int *fib = generate_fibonacci(MAX_FIB);

    // Print the Fibonacci sequence with colors
    print_fibonacci(fib, MAX_FIB);

    // Free the allocated memory
    free(fib);

    return 0;
}