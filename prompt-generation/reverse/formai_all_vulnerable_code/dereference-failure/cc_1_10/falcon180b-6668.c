//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int *arr;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *create_array(int size) {
    DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
    arr->arr = (int *)malloc(sizeof(int) * size);
    arr->size = 0;
    arr->capacity = size;
    return arr;
}

void destroy_array(DynamicArray *arr) {
    free(arr->arr);
    free(arr);
}

void resize_array(DynamicArray *arr, int new_capacity) {
    int *new_arr = (int *)malloc(sizeof(int) * new_capacity);
    memcpy(new_arr, arr->arr, sizeof(int) * arr->size);
    free(arr->arr);
    arr->arr = new_arr;
    arr->capacity = new_capacity;
}

void add_element(DynamicArray *arr, int element) {
    if (arr->size >= arr->capacity) {
        resize_array(arr, arr->capacity * 2);
    }
    arr->arr[arr->size++] = element;
}

int find_element(DynamicArray *arr, int element) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, m, k, element, position;
    DynamicArray *arr;

    scanf("%d", &n);
    arr = create_array(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        add_element(arr, element);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &element);
        position = find_element(arr, element);
        if (position == -1) {
            printf("Element not found.\n");
        } else {
            printf("Element found at position %d.\n", position);
        }
    }

    destroy_array(arr);

    return 0;
}