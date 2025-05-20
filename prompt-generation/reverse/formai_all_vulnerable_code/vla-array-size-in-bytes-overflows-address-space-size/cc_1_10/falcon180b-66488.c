//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX_VALUE 100000

// Function to compare two integers
int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;

    if (x > y) {
        return 1;
    } else if (x < y) {
        return -1;
    } else {
        return 0;
    }
}

// Function to sort the array using bucket sort
void bucketSort(int arr[], int n) {
    int i, j, k, count[MAX_SIZE] = {0};
    int *bucket[MAX_SIZE];

    // Create an array of empty buckets
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *)malloc(MAX_VALUE * sizeof(int));
    }

    // Distribute the elements into different buckets
    for (i = 0; i < n; i++) {
        count[(arr[i] / 10000) % MAX_SIZE]++;
    }

    // Sort the elements in each bucket using quicksort
    for (i = 0; i < MAX_SIZE; i++) {
        if (count[i] > 0) {
            qsort(bucket[i], count[i], sizeof(int), compare);
        }
    }

    // Concatenate the sorted buckets back into the original array
    for (i = 0; i < n; i++) {
        j = (arr[i] / 10000) % MAX_SIZE;
        k = 0;

        while (bucket[j][k]!= arr[i]) {
            k++;
        }

        arr[i] = bucket[j][k++];
    }

    // Free the memory allocated for buckets
    for (i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }
}

// Function to print the sorted array
void printArray(int arr[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Main function
int main() {
    int n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}