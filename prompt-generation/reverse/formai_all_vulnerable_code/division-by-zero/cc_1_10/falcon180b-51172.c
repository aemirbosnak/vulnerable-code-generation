//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define MAX_VALUE 1000
#define BUCKET_SIZE 10

int main() {
    int i, j, n, max_value, min_value, range, bucket_size;
    int *array, *sorted_array;
    clock_t start_time, end_time;
    double elapsed_time;

    srand(time(NULL));
    max_value = rand() % MAX_VALUE + 1;
    min_value = rand() % MAX_VALUE + 1;
    range = max_value - min_value;
    n = rand() % MAX_SIZE + 1;
    bucket_size = range / BUCKET_SIZE;

    array = (int *)malloc(n * sizeof(int));
    sorted_array = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        array[i] = rand() % range + min_value;
    }

    start_time = clock();
    for (i = 0; i < n; i++) {
        sorted_array[i] = array[i];
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < BUCKET_SIZE; j++) {
            if (sorted_array[i] >= j * bucket_size && sorted_array[i] < (j + 1) * bucket_size) {
                break;
            }
        }
        sorted_array[i] = j * bucket_size;
    }
    for (i = 0; i < n; i++) {
        array[i] = sorted_array[i];
    }
    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Bucket sort implementation example program\n");
    printf("Max value: %d\n", max_value);
    printf("Min value: %d\n", min_value);
    printf("Range: %d\n", range);
    printf("Number of elements: %d\n", n);
    printf("Bucket size: %d\n", bucket_size);
    printf("Elapsed time: %.6f seconds\n", elapsed_time);

    free(array);
    free(sorted_array);

    return 0;
}