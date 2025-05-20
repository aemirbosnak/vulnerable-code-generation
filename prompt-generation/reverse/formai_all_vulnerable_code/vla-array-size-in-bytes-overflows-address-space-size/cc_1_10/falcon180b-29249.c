//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function to generate random integers between min and max
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void bucketSort(int arr[], int n) {
    int i, j, index;
    int *bucket[MAX_SIZE]; // Array of buckets

    // Create n empty buckets
    for (i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(sizeof(int));
    }

    // Insert each element into its respective bucket
    for (i = 0; i < n; i++) {
        index = arr[i] * n / (MAX_SIZE - 1);
        if (index == n - 1)
            index--;
        bucket[index] = (int *)realloc(bucket[index], sizeof(int) * (++bucket[index][0]));
        bucket[index][bucket[index][0] - 1] = arr[i];
    }

    // Concatenate all the buckets back into the original array
    for (i = 0, j = 0; i < n; i++) {
        while (bucket[i][j]!= -1) {
            arr[j] = bucket[i][j];
            j++;
        }
    }
}

int main() {
    int i, n;

    // Get the number of elements to be sorted from the user
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    // Create an array of n elements
    int arr[n];

    // Fill the array with random integers between 0 and 100
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = randInt(0, 100);
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}