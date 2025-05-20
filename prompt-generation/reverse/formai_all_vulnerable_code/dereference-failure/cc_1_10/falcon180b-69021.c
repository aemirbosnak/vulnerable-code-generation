//Falcon-180B DATASET v1.0 Category: Sorting ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
} Array;

void init_array(Array *array, int size) {
    array->data = (int *)malloc(size * sizeof(int));
    array->size = size;
}

void free_array(Array *array) {
    free(array->data);
}

void print_array(Array array) {
    int i;
    for (i = 0; i < array.size; i++) {
        printf("%d ", array.data[i]);
    }
    printf("\n");
}

void selection_sort(Array array) {
    int i, j, min_index;
    for (i = 0; i < array.size - 1; i++) {
        min_index = i;
        for (j = i + 1; j < array.size; j++) {
            if (array.data[j] < array.data[min_index]) {
                min_index = j;
            }
        }
        if (min_index!= i) {
            int temp = array.data[i];
            array.data[i] = array.data[min_index];
            array.data[min_index] = temp;
        }
    }
}

int main() {
    Array arr;
    int i;

    srand(time(NULL));
    init_array(&arr, MAX_SIZE);

    for (i = 0; i < MAX_SIZE; i++) {
        arr.data[i] = rand() % 100;
    }

    printf("Before sorting:\n");
    print_array(arr);

    selection_sort(arr);

    printf("After sorting:\n");
    print_array(arr);

    free_array(&arr);

    return 0;
}