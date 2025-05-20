//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: lively
// Buckle up, folks! Let's embark on a benchmarking expedition!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Our fearless function, ready to dance on the CPU's stage
void doStuff(int n) {
    // Allocate a generous arena for our computations
    int *arena = malloc(n * sizeof(int));

    // Set the arena ablaze with random numbers
    srand(time(NULL));
    for (int i = 0; i < n; i++) { arena[i] = rand(); }

    // Unleash a whirlwind of calculations
    for (int i = 0; i < n; i++) {
        arena[i] *= 7;
        arena[i] /= 3;
        arena[i] %= 5;
        arena[i] += 1;
    }

    // Clean up our act, returning the arena to its slumber
    free(arena);
}

// The stopwatch that will measure our function's agility
clock_t start, end;

// Let the benchmarking games begin!
int main(int argc, char **argv) {
    printf("Buckle in, folks! Warm-up run commencing...\n");

    // Let the function get its bearings
    doStuff(100000);

    // Time to put our function through its paces!
    int iterations = atoi(argv[1]);
    printf("Ready for the grand spectacle! %d iterations, brace yourselves...\n", iterations);

    start = clock();
    for (int i = 0; i < iterations; i++) { doStuff(100000); }
    end = clock();

    // Calculate the elapsed time, the heart of our adventure
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Ta-da! The time it took: %f seconds\n", elapsed);

    // A round of applause for our function's performance
    printf("Bravo, bravo! Our function danced with grace...\n");

    return 0;
}