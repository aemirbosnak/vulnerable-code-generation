//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_SIZE 10
#define GROW_AMOUNT 10

typedef struct {
    int *data;
    int capacity;
    int size;
} Array;

Array *create_array() {
    Array *arr = (Array *)malloc(sizeof(Array));
    arr->capacity = MIN_SIZE;
    arr->size = 0;
    arr->data = (int *)calloc(arr->capacity, sizeof(int));
    return arr;
}

void resize(Array *arr) {
    arr->capacity *= 2;
    arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
}

void push_back(Array *arr, int value) {
    if (arr->size == arr->capacity) {
        resize(arr);
    }
    arr->data[arr->size] = value;
    arr->size++;
}

int binary_search(Array *arr, int target, int *index) {
    int left = 0, right = arr->size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr->data[mid] == target) {
            *index = mid;
            return 1;
        }
        if (arr->data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    *index = -1;
    return 0;
}

int main() {
    Array *arr = create_array();

    push_back(arr, 5);
    push_back(arr, 8);
    push_back(arr, 3);
    push_back(arr, 12);
    push_back(arr, 7);
    push_back(arr, 15);

    int target_values[] = {3, 5, 7, 8, 12, 15, 22, 35};
    int target_count = sizeof(target_values) / sizeof(int);
    int *indices = (int *)calloc(target_count, sizeof(int));

    for (int i = 0; i < target_count; i++) {
        int index;
        if (binary_search(arr, target_values[i], &index) == 1) {
            printf("Found %d at index %d\n", target_values[i], index);
            indices[i] = index;
        } else {
            printf("Could not find %d\n", target_values[i]);
            indices[i] = -1;
        }
    }

    free(indices);

    return 0;
}