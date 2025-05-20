//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_VAL 1000
#define BUCKET_COUNT 10

// Structure to represent a bucket
typedef struct Bucket {
    int *elements;
    int count;
} Bucket;

// Function to create a bucket
Bucket* createBucket(int size) {
    Bucket *bucket = (Bucket *)malloc(sizeof(Bucket));
    bucket->elements = (int *)malloc(size * sizeof(int));
    bucket->count = 0;
    return bucket;
}

// Function to free a bucket
void freeBucket(Bucket *bucket) {
    free(bucket->elements);
    free(bucket);
}

// Hash function to map a value to a bucket index
int hashFunction(int value) {
    return value / (MAX_VAL / BUCKET_COUNT);
}

// Function to perform insertion sort on a bucket
void insertionSort(int *array, int n) {
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// Function to print the sorted array
void printSortedArray(int *array, int n) {
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to perform bucket sort
void bucketSort(int *array, int n) {
    // Create the buckets
    Bucket **buckets = (Bucket **)malloc(BUCKET_COUNT * sizeof(Bucket *));
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = createBucket(n);
    }

    // Place each number in its corresponding bucket
    for (int i = 0; i < n; i++) {
        int index = hashFunction(array[i]);
        buckets[index]->elements[buckets[index]->count++] = array[i];
    }

    // Sort each bucket and collect the results
    int idx = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (buckets[i]->count > 0) {
            insertionSort(buckets[i]->elements, buckets[i]->count);
            for (int j = 0; j < buckets[i]->count; j++) {
                array[idx++] = buckets[i]->elements[j];
            }
        }
        freeBucket(buckets[i]);
    }
    
    free(buckets);
}

// Main function to demonstrate bucket sort
int main() {
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    int *array = (int *)malloc(n * sizeof(int));
    printf("Enter %d integers (0 to %d):\n", n, MAX_VAL);
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        if (temp < 0 || temp > MAX_VAL) {
            printf("Please enter a valid number between 0 and %d.\n", MAX_VAL);
            free(array);
            return 1;
        }
        array[i] = temp;
    }

    // Call bucket sort
    bucketSort(array, n);

    // Print the sorted array
    printSortedArray(array, n);

    // Free the allocated memory
    free(array);

    return 0;
}