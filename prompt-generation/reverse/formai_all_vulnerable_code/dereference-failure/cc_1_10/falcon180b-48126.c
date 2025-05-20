//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} Array;

Array create_array(int size) {
    Array arr;
    arr.data = malloc(size * sizeof(int));
    arr.size = size;
    return arr;
}

void destroy_array(Array arr) {
    free(arr.data);
}

void fill_array(Array arr, int value) {
    for (int i = 0; i < arr.size; i++) {
        arr.data[i] = value;
    }
}

void print_array(Array arr) {
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");
}

int sum_array(Array arr) {
    int sum = 0;
    for (int i = 0; i < arr.size; i++) {
        sum += arr.data[i];
    }
    return sum;
}

int main() {
    Array arr1 = create_array(MAX_SIZE);
    Array arr2 = create_array(MAX_SIZE);
    int value = 42;

    fill_array(arr1, value);
    fill_array(arr2, value);

    printf("Sum of arr1: %d\n", sum_array(arr1));
    printf("Sum of arr2: %d\n", sum_array(arr2));

    destroy_array(arr1);
    destroy_array(arr2);

    return 0;
}