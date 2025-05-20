//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_TERMS 50

int main() {
    int i, j, term_count = 0;
    double fib_ratio = 1.61803398875;
    double scale_factor = 1.0;
    double term1 = 1.0, term2 = 1.0;
    double *fib_sequence = (double *)malloc(NUM_TERMS * sizeof(double));

    srand(time(NULL));

    // Generate random starting values for the sequence
    for (i = 0; i < 2; i++) {
        term1 = rand() % 1000;
        term2 = rand() % 1000;
    }

    fib_sequence[0] = term1;
    fib_sequence[1] = term2;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Press ENTER to start the sequence...\n");
    getchar();

    while (term_count < NUM_TERMS) {
        for (i = 0; i < term_count; i++) {
            printf("%d: %.2f\t", i+1, fib_sequence[i]);
        }
        printf("\n");

        term_count++;

        // Generate the next term in the sequence
        term1 = fib_sequence[term_count-1] + fib_sequence[term_count-2];
        term2 = fib_sequence[term_count-2] + term1 * fib_ratio;
        fib_sequence[term_count] = term2 * scale_factor;
        scale_factor *= 2.0;
    }

    printf("\nThanks for using the Fibonacci Sequence Visualizer!\n");

    free(fib_sequence);

    return 0;
}