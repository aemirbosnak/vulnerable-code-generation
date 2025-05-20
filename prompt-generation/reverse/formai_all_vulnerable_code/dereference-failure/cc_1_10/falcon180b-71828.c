//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>

#define MAX_DATA_SIZE 1000000
#define NUM_REPEATS 10

typedef struct {
    char *name;
    int (*func)(void *data, int size);
} benchmark_t;

void benchmark_init(benchmark_t *benchmark, char *name, int (*func)(void *data, int size)) {
    benchmark->name = name;
    benchmark->func = func;
}

int benchmark_run(benchmark_t *benchmark, void *data, int size) {
    clock_t start_time = clock();
    int result = benchmark->func(data, size);
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("%s took %.3f seconds to complete.\n", benchmark->name, elapsed_time);
    return result;
}

int sum_array(void *data, int size) {
    int *array = data;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

int multiply_array(void *data, int size) {
    int *array = data;
    int product = 1;
    for (int i = 0; i < size; i++) {
        product *= array[i];
    }
    return product;
}

int main() {
    int *array1 = malloc(sizeof(int) * MAX_DATA_SIZE);
    int *array2 = malloc(sizeof(int) * MAX_DATA_SIZE);
    int *array3 = malloc(sizeof(int) * MAX_DATA_SIZE);
    for (int i = 0; i < MAX_DATA_SIZE; i++) {
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
    }
    benchmark_t sum_benchmark;
    benchmark_init(&sum_benchmark, "Sum", sum_array);
    benchmark_t multiply_benchmark;
    benchmark_init(&multiply_benchmark, "Multiply", multiply_array);
    for (int i = 0; i < NUM_REPEATS; i++) {
        benchmark_run(&sum_benchmark, array1, MAX_DATA_SIZE);
        benchmark_run(&multiply_benchmark, array2, MAX_DATA_SIZE);
    }
    free(array1);
    free(array2);
    free(array3);
    return 0;
}