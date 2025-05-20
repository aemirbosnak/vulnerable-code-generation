//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function to sort array using bucket sort
void bucketSort(int array[], int size) {
    int i, j;
    int minVal = array[0];
    int maxVal = array[0];
    int *buckets;

    // Find the minimum and maximum values in the array
    for (i = 1; i < size; i++) {
        if (array[i] < minVal) {
            minVal = array[i];
        } else if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }

    // Create the buckets
    int bucketSize = (maxVal - minVal) / size + 1;
    buckets = (int*) calloc(size, sizeof(int));

    // Distribute the elements into the buckets
    for (i = 0; i < size; i++) {
        j = (array[i] - minVal) / bucketSize;
        buckets[j]++;
    }

    // Sort the elements in each bucket
    for (i = 0, j = 0; i < size; i++) {
        while ((buckets[i]--) > 0) {
            array[j++] = i * bucketSize + minVal;
        }
    }

    // Free the memory allocated for the buckets array
    free(buckets);
}

int main() {
    int i;
    int array[] = {31, 49, 38, 27, 41, 45};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Unsorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    bucketSort(array, size);

    printf("\nSorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\nHappy bucket sorting!\n");
    return 0;
}