//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100
#define BUCKET_COUNT 10

// Function to initialize the buckets
void initializeBuckets(int buckets[][MAX_NUM], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < MAX_NUM; j++) {
            buckets[i][j] = -1; // -1 signifies an empty slot
        }
    }
}

// Function to perform insertion sort on a bucket
void insertionSort(int bucket[], int n) {
    for (int i = 1; i < n; i++) {
        int key = bucket[i];
        int j = i - 1;

        // Shifting values upward in the bucket
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// The master function orchestrating the sort
void bucketSort(int arr[], int n) {
    // Hold the buckets
    int buckets[BUCKET_COUNT][MAX_NUM];
    int bucketCount[BUCKET_COUNT] = {0}; // to track elements in each bucket

    // Initialize buckets
    initializeBuckets(buckets, BUCKET_COUNT);

    // Map the values into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * BUCKET_COUNT / (MAX_NUM + 1); // Finding the right bucket index
        buckets[index][bucketCount[index]] = arr[i]; // Placing in the appropriate bucket
        bucketCount[index]++; // Incrementing the count of elements in that bucket
    }

    // Sorting each bucket and merging
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        // Sort the individual buckets using insertion sort
        insertionSort(buckets[i], bucketCount[i]);

        // Now merging the sorted buckets into the original array
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int n;

    // A riddle that beckons the seeker
    printf("Ah! You wish to sort the numbers! How many numbers will you conjure? ");
    scanf("%d", &n);
    
    // Entering the world of numbers
    int arr[n];
    printf("Speak thy numbers, and they shall be captured:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // The moment of truth unfolds
    printf("Unraveling the chaos, behold the numbers before sorting:\n");
    printArray(arr, n);

    // The magic of Bucket Sort
    bucketSort(arr, n);

    // The grand reveal of the sorted numbers
    printf("With a wave of code, your numbers are sorted:\n");
    printArray(arr, n);
    
    return 0;
}