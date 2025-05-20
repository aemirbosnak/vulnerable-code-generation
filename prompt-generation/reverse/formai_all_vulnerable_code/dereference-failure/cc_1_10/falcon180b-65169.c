//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bucket sort
void bucket_sort(int arr[], int n) {
    // Create an array of empty lists
    int bucket[MAX] = { 0 };

    // Calculate the range of the input array
    int range = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > range) {
            range = arr[i];
        }
    }

    // Create a list of empty lists
    int **output = (int **) malloc(range * sizeof(int *));
    for (int i = 0; i < range; i++) {
        output[i] = (int *) malloc(n * sizeof(int));
    }

    // Place each element in its appropriate bucket
    for (int i = 0; i < n; i++) {
        int index = arr[i] * MAX / range;
        output[index][bucket[index]++] = arr[i];
    }

    // Concatenate the sorted buckets
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < MAX) {
            if (bucket[j] > 0) {
                arr[i] = output[j][--bucket[j]];
                i++;
            }
            j++;
        }
    }

    // Free the memory allocated for the output array
    for (int i = 0; i < range; i++) {
        free(output[i]);
    }
    free(output);
}

int main() {
    int arr[] = { 3, 2, 1, 5, 4, 6, 7, 8, 9, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}