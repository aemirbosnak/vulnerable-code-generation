//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 10000000

int main() {
    int i, j;
    char *array[ARRAY_SIZE];
    char *temp;

    // Initialize the array
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = malloc(100 * sizeof(char));
        if (!array[i]) {
            fprintf(stderr, "Error allocating memory!\n");
            return EXIT_FAILURE;
        }
    }

    // Bench the memory writes
    clock_t start = clock();
    for (i = 0; i < ARRAY_SIZE; i++) {
        memset(array[i], 'a', 100 * sizeof(char));
    }
    clock_t end = clock();
    double mem_write_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Bench the memory reads
    start = clock();
    for (i = 0; i < ARRAY_SIZE; i++) {
        for (j = 0; j < 100; j++) {
            temp = array[i][j];
        }
    }
    end = clock();
    double mem_read_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Bench the sorting
    start = clock();
    qsort((void*)array, ARRAY_SIZE, sizeof(char*), strcmp);
    end = clock();
    double sort_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the results
    printf("Memory write time: %lf seconds\n", mem_write_time);
    printf("Memory read time: %lf seconds\n", mem_read_time);
    printf("Sorting time: %lf seconds\n", sort_time);

    // Free the array
    for (i = 0; i < ARRAY_SIZE; i++) {
        free(array[i]);
    }

    return EXIT_SUCCESS;
}