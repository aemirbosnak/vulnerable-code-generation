//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 11
#define BUCKET_COUNT 5

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bucketSort(int array[], int size) {
    int i, j;
    int min_value = array[0];
    int max_value = array[0];
    int bucket_count = BUCKET_COUNT;

    // Find the minimum and maximum values in the array
    for (i = 1; i < size; i++) {
        if (array[i] < min_value) {
            min_value = array[i];
        } else if (array[i] > max_value) {
            max_value = array[i];
        }
    }

    // Calculate the size of each bucket
    float bucket_size = (max_value - min_value + 1) / (float) bucket_count;

    // Create the buckets
    int **buckets = malloc(sizeof(int *) * bucket_count);
    for (i = 0; i < bucket_count; i++) {
        buckets[i] = malloc(sizeof(int) * size);
    }

    // Distribute the elements into the buckets
    for (i = 0; i < size; i++) {
        int bucket_index = (int) ((array[i] - min_value) / bucket_size);
        int *bucket = buckets[bucket_index];
        bucket[i] = array[i];
    }

    // Sort the individual buckets
    for (i = 0; i < bucket_count; i++) {
        int *bucket = buckets[i];
        int bucket_size = sizeof(bucket) / sizeof(bucket[0]);
        for (j = 0; j < bucket_size; j++) {
            int temp = bucket[j];
            int k = j - 1;
            while (k >= 0 && bucket[k] > temp) {
                bucket[k + 1] = bucket[k];
                k--;
            }
            bucket[k + 1] = temp;
        }
    }

    // Concatenate the sorted buckets
    int index = 0;
    for (i = 0; i < bucket_count; i++) {
        int *bucket = buckets[i];
        int bucket_size = sizeof(bucket) / sizeof(bucket[0]);
        for (j = 0; j < bucket_size; j++) {
            array[index++] = bucket[j];
        }
    }

    // Free the memory allocated for the buckets
    for (i = 0; i < bucket_count; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    int array[ARRAY_SIZE] = {4, 9, 2, 7, 5, 3, 8, 1, 10, 6, 0};
    printf("Unsorted array: ");
    printArray(array, ARRAY_SIZE);

    bucketSort(array, ARRAY_SIZE);

    printf("Sorted array: ");
    printArray(array, ARRAY_SIZE);

    return 0;
}