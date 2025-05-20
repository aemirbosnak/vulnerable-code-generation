//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

void generate_random_string(char* str, int length) {
    const char alphanum[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < length; i++) {
        str[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    str[length] = '\0';
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <string_length> <iterations>\n", argv[0]);
        return 1;
    }

    int string_length = atoi(argv[1]);
    int iterations = atoi(argv[2]);

    if (string_length <= 0 || iterations <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    char* input_string = malloc(string_length + 1);
    char* output_string = malloc(string_length + 1);

    generate_random_string(input_string, string_length);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < iterations; i++) {
        strcpy(output_string, input_string);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

    printf("String length: %d\n", string_length);
    printf("Iterations: %d\n", iterations);
    printf("Elapsed time: %.6f seconds\n", elapsed_time);

    free(input_string);
    free(output_string);

    return 0;
}