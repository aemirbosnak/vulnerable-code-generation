//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

void check_memory(void* ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(EXIT_FAILURE);
    }
}

void check_input(int* input, int size) {
    for (int i = 0; i < size; i++) {
        if (input[i] < 0 || input[i] > 100) {
            fprintf(stderr, "Error: Invalid input. Value %d is out of range [0, 100]\n", input[i]);
            exit(EXIT_FAILURE);
        }
    }
}

void check_sum(double* data, int size, double expected_sum) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    if (fabs(sum - expected_sum) > 0.001) {
        fprintf(stderr, "Error: Sum of data does not match expected value. Expected %lf, found %lf\n", expected_sum, sum);
        exit(EXIT_FAILURE);
    }
}

void process_data(int* input, double* output, int size) {
    check_memory(input);
    check_memory(output);

    for (int i = 0; i < size; i++) {
        input[i] *= 2;
        output[i] = pow(input[i], 0.5);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Error: Incorrect number of arguments. Expected 2, found %d\n", argc - 1);
        exit(EXIT_FAILURE);
    }

    int size = atoi(argv[1]);
    check_input(argv[2], size);

    int* input = (int*) calloc(size, sizeof(int));
    check_memory(input);

    sscanf(argv[2], "%s", input);

    double* output = (double*) calloc(size, sizeof(double));
    check_memory(output);

    process_data(input, output, size);

    double expected_sum = 1000.0;

    check_sum(output, size, expected_sum);

    for (int i = 0; i < size; i++) {
        printf("Output[%d] = %lf\n", i, output[i]);
    }

    free(input);
    free(output);

    return EXIT_SUCCESS;
}