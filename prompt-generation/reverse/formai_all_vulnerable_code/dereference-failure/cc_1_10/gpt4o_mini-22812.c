//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_fibonacci(int n) {
    unsigned long long int a = 0, b = 1, next;
    
    printf("\nFibonacci Sequence:\n");
    printf("Index\tValue\n");
    printf("-----\t------\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d\t%llu\n", i, a);
        next = a + b;
        a = b;
        b = next;
        usleep(500000); // Slowing down the output for visualization
    }
}

void visualize_fibonacci(int n) {
    unsigned long long int a = 0, b = 1, next;
    
    printf("\nVisualizing Fibonacci Sequence:\n");
    
    for (int i = 0; i < n; i++) {
        next = a + b;
        a = b;
        b = next;

        // Dynamic visualization based on the Fibonacci value
        printf("%-*s", (int)(b / 100000), ""); // Space according to value
        printf("*\n");
        usleep(500000); // Slowing down the output for visualization
    }
}

int main(int argc, char *argv[]) {
    int n;

    if (argc < 2) {
        printf("Usage: %s <number of Fibonacci terms>\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);
    if (n <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    print_fibonacci(n);
    visualize_fibonacci(n);
    
    return 0;
}