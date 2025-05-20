//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int *arr;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *create_array(int capacity) {
    DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
    arr->arr = (int *)malloc(capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}

void destroy_array(DynamicArray *arr) {
    free(arr->arr);
    free(arr);
}

void resize_array(DynamicArray *arr, int new_capacity) {
    int *new_arr = (int *)malloc(new_capacity * sizeof(int));
    memcpy(new_arr, arr->arr, arr->size * sizeof(int));
    free(arr->arr);
    arr->arr = new_arr;
    arr->capacity = new_capacity;
}

void add_element(DynamicArray *arr, int element) {
    if (arr->size == arr->capacity) {
        resize_array(arr, arr->capacity * 2);
    }
    arr->arr[arr->size++] = element;
}

int main() {
    srand(time(NULL));

    DynamicArray *arr = create_array(MAX_SIZE);

    int i;
    for (i = 0; i < 100; i++) {
        int element = rand() % 1000;
        add_element(arr, element);
    }

    int sum = 0;
    int max_sum = 0;
    int start_index = 0;
    int end_index = 0;

    for (i = 0; i < arr->size; i++) {
        sum += arr->arr[i];

        if (sum > max_sum) {
            max_sum = sum;
            start_index = end_index;
            end_index = i;
        }

        if (sum < 0) {
            sum = 0;
            start_index = i + 1;
        }
    }

    printf("Max sum: %d\n", max_sum);
    printf("Subarray: ");
    for (i = start_index; i <= end_index; i++) {
        printf("%d ", arr->arr[i]);
    }
    printf("\n");

    destroy_array(arr);

    return 0;
}