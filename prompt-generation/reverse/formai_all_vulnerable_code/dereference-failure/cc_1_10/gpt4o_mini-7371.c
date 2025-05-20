//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printFibonacci(int terms, int delay, char visualChar) {
    unsigned long long a = 0, b = 1, next;
    
    printf("\nFibonacci Sequence:\n");
    for (int i = 1; i <= terms; i++) {
        if (i == 1) {
            printf("%llu ", a);
        } else if (i == 2) {
            printf("%llu ", b);
        } else {
            next = a + b;
            a = b;
            b = next;
            printf("%llu ", next);
        }

        // Visualization
        for (int j = 0; j < (next % 10); j++) {  // Modulo for length of visual
            printf("%c", visualChar);
        }
        
        printf("\n");
        
        // Delay for visualization effect
        usleep(delay * 1000);
    }
}

int main(int argc, char *argv[]) {
    int terms = 10;           // Default number of terms
    int delay = 500;         // Default delay in milliseconds
    char visualChar = '*';   // Default visualization character

    // Get user input for configuration
    if (argc > 1) {
        terms = atoi(argv[1]);
    }
    if (argc > 2) {
        delay = atoi(argv[2]);
    }
    if (argc > 3) {
        visualChar = argv[3][0];
    }

    // Ensure valid input
    if (terms < 1) {
        printf("Please enter a positive number of terms.\n");
        return 1;
    }
    if (delay < 0) {
        printf("Please enter a non-negative delay time.\n");
        return 1;
    }

    printFibonacci(terms, delay, visualChar);
    return 0;
}