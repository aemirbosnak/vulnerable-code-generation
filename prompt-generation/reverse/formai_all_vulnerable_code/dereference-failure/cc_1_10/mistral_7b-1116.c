//MISTRAL-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FIB 50 // Maximum Fibonacci number to print
#define LINE_LEN (MAX_FIB / 2) // Half of the maximum Fibonacci number

void print_fibonacci(int n) {
    int fib_prev = 0, fib_current = 1;

    if (n <= 0) {
        printf("Invalid input. Please enter a positive number.\n");
        return;
    }

    if (n == 1) {
        printf("Fibonacci sequence up to %d:\n%d\n", n, fib_prev);
        return;
    }

    printf("Fibonacci sequence up to %d:\n%d, %d, ", fib_prev, fib_prev, fib_current);

    for (int i = 2; i < n; ++i) {
        int next_number = fib_prev + fib_current;
        fib_prev = fib_current;
        fib_current = next_number;

        if (i < n - 1)
            printf("%d, ", next_number);
        else
            printf("%d\n", next_number);
    }
}

void print_diagram(int fib) {
    char diagram[LINE_LEN + 1];
    memset(diagram, '*', LINE_LEN);
    diagram[LINE_LEN] = '\0';

    int fib_prev = 0, fib_current = 1;
    for (int i = 0; i < fib; ++i) {
        if (i <= fib_prev) {
            diagram[i] = ' ';
            fib_prev = fib_current;
            fib_current += fib_prev;
        }
    }

    printf("\nFibonacci number %d diagram:\n%s\n", fib, diagram);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number of Fibonacci numbers to print>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    print_fibonacci(n);
    print_diagram(n);

    return 0;
}