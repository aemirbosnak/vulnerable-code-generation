//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 10

// Structure to hold the array of integers
typedef struct {
    int *arr;
    size_t len;
} int_array_t;

// Function to sort the array of integers using quicksort
int quicksort(int_array_t *arr) {
    // Base case: If the length of the array is 1 or less, return
    if (arr->len <= 1) return 0;

    // Partition the array into two parts: elements less than and greater than the pivot
    int pivot = arr->arr[arr->len / 2];
    int i = 0;
    for (size_t j = 0; j < arr->len; j++) {
        if (arr->arr[j] < pivot) {
            i++;
            arr->arr[i] = arr->arr[j];
        }
    }

    // Recursively sort the two partitions
    int left = quicksort(arr->arr + i);
    int right = quicksort(arr->arr + arr->len - i);

    // Combine the two partitions and return the result
    for (size_t j = 0; j < arr->len - i; j++) {
        arr->arr[j] = arr->arr[j + i];
    }
    arr->len -= i;
    return left + right;
}

// Function to sort the array of integers using insertion sort
int insertion_sort(int_array_t *arr) {
    int i, j;
    for (i = 1; i < arr->len; i++) {
        int key = arr->arr[i];
        j = i - 1;
        while (j >= 0 && arr->arr[j] > key) {
            arr->arr[j + 1] = arr->arr[j];
            j--;
        }
        arr->arr[j + 1] = key;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int_array_t arr;
    arr.arr = malloc(ARRAY_SIZE * sizeof(int));
    arr.len = ARRAY_SIZE;
    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        arr.arr[i] = rand() % 100;
    }

    // Sort the array using quicksort
    quicksort(&arr);

    // Print the sorted array
    for (size_t i = 0; i < arr.len; i++) {
        printf("%d ", arr.arr[i]);
    }
    printf("\n");

    // Sort the array using insertion sort
    insertion_sort(&arr);

    // Print the sorted array
    for (size_t i = 0; i < arr.len; i++) {
        printf("%d ", arr.arr[i]);
    }
    printf("\n");

    return 0;
}