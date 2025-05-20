//FormAI DATASET v1.0 Category: Benchmarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int size, i, j, k;
    double *arr1, *arr2, *result;
    clock_t start, end;
    double cpu_time_used1, cpu_time_used2;

    printf("Enter the size of the arrays:\n");
    scanf("%d", &size);

    /* Allocate memory for arrays */
    arr1 = (double *) malloc(size * sizeof(double));
    arr2 = (double *) malloc(size * sizeof(double));
    result = (double *) malloc(size * sizeof(double));

    /* Fill arrays with random numbers */
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        arr1[i] = rand() / (double) RAND_MAX;
        arr2[i] = rand() / (double) RAND_MAX;
    }

    /* Benchmarking loop for multiplication operation */
    start = clock();
    for (i = 0; i < size; i++) {
        result[i] = arr1[i] * arr2[i];
    }
    end = clock();
    cpu_time_used1 = ((double) (end - start)) / CLOCKS_PER_SEC;

    /* Benchmarking loop for addition operation */
    start = clock();
    for (j = 0; j < size; j++) {
        result[j] = arr1[j] + arr2[j];
    }
    end = clock();
    cpu_time_used2 = ((double) (end - start)) / CLOCKS_PER_SEC;

    /* Print results */
    printf("Time taken for multiplication operation: %f seconds\n", cpu_time_used1);
    printf("Time taken for addition operation: %f seconds\n", cpu_time_used2);

    /* Free allocated memory */
    free(arr1);
    free(arr2);
    free(result);

    return 0;
}