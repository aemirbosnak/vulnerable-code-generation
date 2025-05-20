//FormAI DATASET v1.0 Category: Benchmarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000

void initialize_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % size;
    }
}

double time_diff(struct timespec start, struct timespec end) {
    double start_sec = (double)start.tv_sec * 1000000000.0 + (double)start.tv_nsec;
    double end_sec = (double)end.tv_sec * 1000000000.0 + (double)end.tv_nsec;
    if (end_sec < start_sec) {
        return 0;
    } else {
        return (end_sec - start_sec) / 1000000000.0;
    }
}

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void test_sort(int *array, int size) {
    struct timespec start, end;
    double time_elapsed;

    printf("Sorting %d elements...\n", size);
    clock_gettime(CLOCK_REALTIME, &start);
    qsort(array, size, sizeof(int), cmp);
    clock_gettime(CLOCK_REALTIME, &end);

    time_elapsed = time_diff(start, end);
    printf("Time Elapsed: %f seconds\n\n", time_elapsed);
}

int main(int argc, char *argv[]) {
    int *a = (int*)malloc(sizeof(int) * ARRAY_SIZE);

    srand(time(NULL));
    initialize_array(a, ARRAY_SIZE);

    test_sort(a, ARRAY_SIZE);

    free(a);

    return 0;
}