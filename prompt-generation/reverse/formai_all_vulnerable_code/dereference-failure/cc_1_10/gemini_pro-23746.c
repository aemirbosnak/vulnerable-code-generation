//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
} Array;

Array* create_array(int size) {
    Array *arr = malloc(sizeof(Array));
    arr->arr = malloc(sizeof(int) * size);
    arr->size = size;
    return arr;
}

void free_array(Array *arr) {
    free(arr->arr);
    free(arr);
}

int binary_search(Array *arr, int target) {
    int left = 0;
    int right = arr->size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr->arr[mid] == target) {
            return mid;
        } else if (arr->arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    Array *arr = create_array(10);
    for (int i = 0; i < arr->size; i++) {
        arr->arr[i] = i;
    }
    int target = 5;
    int result = binary_search(arr, target);
    if (result == -1) {
        printf("Target not found\n");
    } else {
        printf("Target found at index %d\n", result);
    }
    free_array(arr);
    return 0;
}