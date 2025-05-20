//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define SIZE 1000000

void initialize_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100; // Random values between 0 and 99
    }
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void sum_arrays(int *array1, int *array2, int *result, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        result[i] = array1[i] + array2[i];
    }
}

int main() {
    int *array1 = (int *)malloc(SIZE * sizeof(int));
    int *array2 = (int *)malloc(SIZE * sizeof(int));
    int *result = (int *)malloc(SIZE * sizeof(int));
    
    if (array1 == NULL || array2 == NULL || result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL)); // Seed the random number generator

    // Initialize arrays
    initialize_array(array1, SIZE);
    initialize_array(array2, SIZE);

    // Uncomment to print initial arrays
    // print_array(array1, SIZE);
    // print_array(array2, SIZE);
    
    // Sum the arrays
    clock_t start = clock();
    sum_arrays(array1, array2, result, SIZE);
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sum arrays: %lf seconds\n", elapsed_time);

    // Uncomment to print the result array
    // print_array(result, SIZE);

    // Free allocated memory
    free(array1);
    free(array2);
    free(result);

    return 0;
}