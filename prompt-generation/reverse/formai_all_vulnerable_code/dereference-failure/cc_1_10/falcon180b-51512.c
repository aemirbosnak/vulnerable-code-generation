//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MIN_VALUE 1
#define MAX_VALUE 1000000

int main(int argc, char *argv[]) {
    int *array;
    int size;
    int i;
    int sum = 0;
    clock_t start, end;
    double cpu_time_used;

    if (argc!= 2) {
        printf("Usage:./program <array_size>\n");
        exit(1);
    }

    size = atoi(argv[1]);

    if (size < 1 || size > MAX_SIZE) {
        printf("Array size must be between 1 and %d\n", MAX_SIZE);
        exit(1);
    }

    array = (int *) malloc(size * sizeof(int));

    for (i = 0; i < size; i++) {
        array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    start = clock();

    for (i = 0; i < size; i++) {
        sum += array[i];
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sum of array elements: %d\n", sum);
    printf("CPU time used: %.2f seconds\n", cpu_time_used);

    free(array);

    return 0;
}