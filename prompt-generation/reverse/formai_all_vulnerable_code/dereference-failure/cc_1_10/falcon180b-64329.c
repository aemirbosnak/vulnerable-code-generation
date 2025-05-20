//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

typedef struct {
    int *data;
    int size;
    int capacity;
} Array;

void init_array(Array *array) {
    array->data = (int *)malloc(array->capacity * sizeof(int));
    array->size = 0;
}

void free_array(Array *array) {
    free(array->data);
}

void resize_array(Array *array, int new_capacity) {
    int *new_data = (int *)malloc(new_capacity * sizeof(int));
    int i;
    for (i = 0; i < array->size; i++) {
        new_data[i] = array->data[i];
    }
    free(array->data);
    array->data = new_data;
    array->capacity = new_capacity;
}

void add_to_array(Array *array, int value) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        resize_array(array, array->capacity);
    }
    array->data[array->size++] = value;
}

void print_array(Array *array) {
    int i;
    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

void bucket_sort(Array *array) {
    int i, j, max = 0, min = 1000000;
    int *bucket = (int *)malloc(MAX_SIZE * sizeof(int));
    int *temp = array->data;
    array->data = bucket;
    for (i = 0; i < array->size; i++) {
        if (temp[i] > max) {
            max = temp[i];
        }
        if (temp[i] < min) {
            min = temp[i];
        }
    }
    int range = max - min + 1;
    int bucket_size = MAX_SIZE / range;
    for (i = 0; i < array->size; i++) {
        int bucket_index = (temp[i] - min) / bucket_size;
        if (bucket[bucket_index] == 0) {
            bucket[bucket_index] = 1;
        }
        add_to_array(array, temp[i]);
    }
    for (i = 0; i < array->size; i++) {
        int bucket_index = (temp[i] - min) / bucket_size;
        array->data[i] = bucket[bucket_index];
        bucket[bucket_index] = 0;
    }
    free(bucket);
}

int main() {
    srand(time(NULL));
    Array arr;
    init_array(&arr);
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        add_to_array(&arr, rand() % 1000000);
    }
    printf("Before sorting:\n");
    print_array(&arr);
    bucket_sort(&arr);
    printf("After sorting:\n");
    print_array(&arr);
    free_array(&arr);
    return 0;
}