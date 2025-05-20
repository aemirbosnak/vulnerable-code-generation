//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>

void mysterious_sequence(int length) {
    char *sequence = (char *)malloc(length * sizeof(char));
    if (!sequence) exit(EXIT_FAILURE);
    
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + (rand() % 26);
    }
    
    sequence[length - 1] = '\0';  // Null-terminate the string
    printf("Generated Sequence: %s\n", sequence);
    free(sequence);
}

void complex_computation(int n) {
    long long result = 0;
    for (int i = 1; i <= n; i++) {
        result += i * i;  // The sum of squares
    }
    printf("Sum of squares up to %d: %lld\n", n, result);
}

double get_time_diff(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <sequence_length> <computation_limit>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sequence_length = atoi(argv[1]);
    int computation_limit = atoi(argv[2]);

    printf("Starting mysterious benchmarks...\n");

    struct timeval start, end;

    // Starting the mysterious sequence generation
    gettimeofday(&start, NULL);
    mysterious_sequence(sequence_length);
    gettimeofday(&end, NULL);
    printf("Time taken for sequence generation: %.6f seconds\n", get_time_diff(start, end));

    // Starting complex computation
    gettimeofday(&start, NULL);
    complex_computation(computation_limit);
    gettimeofday(&end, NULL);
    printf("Time taken for complex computation: %.6f seconds\n", get_time_diff(start, end));

    // Time for a mystifying additional task
    gettimeofday(&start, NULL);
    for (int i = 0; i < 1000000; i++) {
        (void)(i * i);  // A meaningless operation
    }
    gettimeofday(&end, NULL);
    printf("Time taken for additional task: %.6f seconds\n", get_time_diff(start, end));

    printf("All mysterious benchmarks completed!\n");
    return EXIT_SUCCESS;
}