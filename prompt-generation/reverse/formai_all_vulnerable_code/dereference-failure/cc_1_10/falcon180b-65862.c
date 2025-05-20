//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000
#define MAX_VAL 1000

// Function to create an empty bucket array
void create_bucket_array(int **arr, int size) {
    *arr = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        (*arr)[i] = 0;
    }
}

// Function to insert an element into the appropriate bucket
void insert_element(int **arr, int size, int val) {
    int index = val / size;
    if (index >= size) {
        index = size - 1;
    }
    (*arr)[index]++;
}

// Function to sort an array using bucket sort
void bucket_sort(int *arr, int size) {
    int *bucket_arr;
    create_bucket_array(&bucket_arr, size);

    // Insert elements into appropriate buckets
    for (int i = 0; i < size; i++) {
        insert_element(&bucket_arr, size, arr[i]);
    }

    // Concatenate the sorted buckets
    int index = 0;
    for (int i = 0; i < size; i++) {
        while (bucket_arr[i] > 0) {
            arr[index++] = i * size;
            bucket_arr[i]--;
        }
    }
}

// Function to print an array
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr;
    arr = (int *)malloc(sizeof(int) * size);

    // Populate the array with random values
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VAL;
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    print_array(arr, size);

    // Sort the array using bucket sort
    bucket_sort(arr, size);

    // Print the sorted array
    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}