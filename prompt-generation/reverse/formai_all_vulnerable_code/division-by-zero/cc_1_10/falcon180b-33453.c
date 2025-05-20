//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_RANGE 1000000

// Function to generate random numbers
void generateRandomNumbers(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANGE;
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int size, int numBuckets) {
    int bucketSize = MAX_RANGE / numBuckets;
    int *bucket[numBuckets];

    // Initialize buckets
    for (int i = 0; i < numBuckets; i++) {
        bucket[i] = malloc(MAX_SIZE * sizeof(int));
    }

    // Place elements in buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / bucketSize;
        int index = 0;
        while (index < MAX_SIZE && bucket[bucketIndex][index]!= 0) {
            index++;
        }
        bucket[bucketIndex][index] = arr[i];
    }

    // Sort elements within buckets
    for (int i = 0; i < numBuckets; i++) {
        int j = 0;
        while (j < MAX_SIZE && bucket[i][j]!= 0) {
            arr[j] = bucket[i][j];
            j++;
        }
    }

    // Free memory
    for (int i = 0; i < numBuckets; i++) {
        free(bucket[i]);
    }
}

// Main function
int main() {
    int size, numBuckets;

    // Get user input
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the number of buckets: ");
    scanf("%d", &numBuckets);

    // Initialize arrays
    int arr[size];
    generateRandomNumbers(arr, size);

    // Perform bucket sort
    bucketSort(arr, size, numBuckets);

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}