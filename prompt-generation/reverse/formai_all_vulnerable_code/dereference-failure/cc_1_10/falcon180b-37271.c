//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_SIZE 1000000
#define MIN_VALUE -1000000
#define MAX_VALUE 1000000

typedef struct {
    int *data;
    int size;
} IntArray;

void init_array(IntArray *array, int size) {
    array->data = (int *)malloc(size * sizeof(int));
    array->size = size;
}

void free_array(IntArray *array) {
    free(array->data);
}

void fill_array(IntArray *array, int min_value, int max_value) {
    srand(time(NULL));
    for (int i = 0; i < array->size; i++) {
        array->data[i] = rand() % (max_value - min_value + 1) + min_value;
    }
}

void print_array(const IntArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

void sort_array(IntArray *array) {
    for (int i = 0; i < array->size - 1; i++) {
        for (int j = i + 1; j < array->size; j++) {
            if (array->data[i] > array->data[j]) {
                int temp = array->data[i];
                array->data[i] = array->data[j];
                array->data[j] = temp;
            }
        }
    }
}

int main() {
    IntArray array;
    init_array(&array, MAX_SIZE);
    fill_array(&array, MIN_VALUE, MAX_VALUE);
    print_array(&array);
    sort_array(&array);
    print_array(&array);
    free_array(&array);
    return 0;
}