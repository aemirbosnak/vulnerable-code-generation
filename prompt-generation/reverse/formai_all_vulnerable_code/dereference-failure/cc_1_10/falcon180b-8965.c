//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_TESTS 10
#define MAX_DATA_SIZE 1000000

int main() {
    int i, j, k;
    int data_size;
    int num_tests;
    double *data1;
    double *data2;
    double *result;
    clock_t start_time, end_time;
    double elapsed_time;

    // Get user input for number of tests and data size
    printf("Enter number of tests: ");
    scanf("%d", &num_tests);

    printf("Enter data size: ");
    scanf("%d", &data_size);

    // Allocate memory for data arrays
    data1 = (double *) malloc(data_size * sizeof(double));
    data2 = (double *) malloc(data_size * sizeof(double));
    result = (double *) malloc(data_size * sizeof(double));

    // Initialize data arrays
    for (i = 0; i < data_size; i++) {
        data1[i] = i;
        data2[i] = i * 2;
    }

    // Perform tests and measure elapsed time
    for (i = 0; i < num_tests; i++) {
        start_time = clock();
        for (j = 0; j < data_size; j++) {
            result[j] = data1[j] + data2[j];
        }
        end_time = clock();
        elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;
        printf("Test %d: Elapsed time = %.6f seconds\n", i+1, elapsed_time);
    }

    // Free memory
    free(data1);
    free(data2);
    free(result);

    return 0;
}