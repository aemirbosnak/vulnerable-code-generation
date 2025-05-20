//MISTRAL-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define WIDTH 41
#define HEIGHT 12
#define DELAY 50000

void print_fibonacci(int n, int x, int y) {
    if (n <= 0) {
        return;
    }

    if (n == 1) {
        printf("\033[%d;%dH%s", y, x, "*");
        return;
    }

    print_fibonacci(n - 1, x, y);
    print_fibonacci(n - 2, x + 2, y + 1);

    printf("\033[%d;%dH%s", y, x + 2, "*");
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char *argv[]) {
    int n;

    if (argc != 2) {
        printf("Usage: %s <Fibonacci number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    n = atoi(argv[1]);

    if (n < 0) {
        printf("Error: Invalid Fibonacci number\n");
        exit(EXIT_FAILURE);
    }

    printf("\033[H"); // Move the cursor to the home position
    printf("\033[2J"); // Clear the terminal screen

    usleep(DELAY);

    print_fibonacci(n, WIDTH / 2, HEIGHT / 2);

    printf("\nFibonacci(%d) = %d\n", n, fibonacci(n));

    return EXIT_SUCCESS;
}