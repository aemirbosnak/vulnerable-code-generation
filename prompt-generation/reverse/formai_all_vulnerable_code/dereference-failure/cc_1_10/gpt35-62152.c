//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the size of the buckets
#define BUCKET_SIZE 10

// Define the maximum value of the input array
#define MAX_VALUE 100

// Define a function to sort the input array using bucket sort
void bucketSort(int array[], int n)
{
    int i, j;
    int count[BUCKET_SIZE] = {0};

    // Create the buckets
    int* bucket[BUCKET_SIZE];
    for (i = 0; i < BUCKET_SIZE; i++) {
        bucket[i] = (int*)malloc(BUCKET_SIZE * sizeof(int));
    }

    // Distribute the elements of the input array into the buckets
    for (i = 0; i < n; i++) {
        int index = array[i] / BUCKET_SIZE;
        bucket[index][count[index]] = array[i];
        count[index]++;
    }

    // Sort each bucket individually using insertion sort
    for (i = 0; i < BUCKET_SIZE; i++) {
        for (j = 1; j < count[i]; j++) {
            int k = j;
            while (k > 0 && bucket[i][k - 1] > bucket[i][k]) {
                int temp = bucket[i][k];
                bucket[i][k] = bucket[i][k - 1];
                bucket[i][k - 1] = temp;
                k--;
            }
        }
    }

    // Concatenate the sorted buckets back into the original array
    int index = 0;
    for (i = 0; i < BUCKET_SIZE; i++) {
        for (j = 0; j < count[i]; j++) {
            array[index] = bucket[i][j];
            index++;
        }
    }

    // Free the memory used by the buckets
    for (i = 0; i < BUCKET_SIZE; i++) {
        free(bucket[i]);
    }
}

// Define a function to print an array
void printArray(int array[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    // Define an input array to be sorted
    int array[] = {22, 45, 12, 8, 10, 6, 72, 80, 33, 55};

    // Get the size of the input array
    int n = sizeof(array) / sizeof(array[0]);

    // Print the original array
    printf("Original array:\n");
    printArray(array, n);

    // Sort the array using bucket sort
    bucketSort(array, n);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(array, n);

    return 0;
}