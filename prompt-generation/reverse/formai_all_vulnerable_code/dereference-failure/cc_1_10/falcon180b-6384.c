//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000
#define MIN_VALUE -1000
#define MAX_VALUE 1000

typedef struct {
    int size;
    int *array;
} IntArray;

void create_array(IntArray *array, int size) {
    array->size = size;
    array->array = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        array->array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
}

void print_array(IntArray array) {
    for (int i = 0; i < array.size; i++) {
        printf("%d ", array.array[i]);
    }
    printf("\n");
}

void sum_array(IntArray array, int *sum) {
    for (int i = 0; i < array.size; i++) {
        *sum += array.array[i];
    }
}

void multiply_array(IntArray array, int factor, IntArray *result) {
    result->size = array.size;
    result->array = (int*)malloc(sizeof(int) * result->size);
    for (int i = 0; i < result->size; i++) {
        result->array[i] = array.array[i] * factor;
    }
}

void average_array(IntArray array, double *average) {
    int sum = 0;
    sum_array(array, &sum);
    *average = (double)sum / array.size;
}

int main() {
    srand(time(NULL));

    IntArray array1, array2, result;
    int sum;
    double average;

    create_array(&array1, MAX_SIZE);
    create_array(&array2, MAX_SIZE);

    printf("Array 1:\n");
    print_array(array1);

    printf("Array 2:\n");
    print_array(array2);

    sum_array(array1, &sum);
    printf("Sum of Array 1: %d\n", sum);

    multiply_array(array1, 2, &result);
    printf("Multiplied Array 1 by 2:\n");
    print_array(result);

    average_array(array1, &average);
    printf("Average of Array 1: %.2lf\n", average);

    free(array1.array);
    free(array2.array);
    free(result.array);

    return 0;
}