//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Function to create an array of given size and fill it with random integers
int *create_array(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

// Function to print an array of given size
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bucket sort on given array of size n
void bucket_sort(int *arr, int n) {
    // Initialize an empty bucket array
    int *bucket[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        bucket[i] = NULL;
    }

    // Place each element in the appropriate bucket
    for (int i = 0; i < n; i++) {
        int index = arr[i] / 10;
        if (bucket[index] == NULL) {
            bucket[index] = (int *)malloc(10 * sizeof(int));
        }
        int *temp = (int *)realloc(bucket[index], (10 * sizeof(int)));
        temp[index] = arr[i];
        bucket[index] = temp;
    }

    // Concatenate the sorted buckets back into the original array
    int j = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]!= NULL) {
            for (int k = 0; k < 10; k++) {
                arr[j++] = bucket[i][k];
            }
        }
    }
}

// Main function
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = create_array(n);

    // Print the unsorted array
    printf("Unsorted array: ");
    print_array(arr, n);

    // Perform bucket sort
    bucket_sort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}