//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100
#define BUCKET_COUNT 10

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void bucketSort(int arr[], int n) {
    // Creating an array of bucket, making each bucket an array
    int bucket[BUCKET_COUNT][MAX_VALUE]; // Array of buckets
    int bucketCount[BUCKET_COUNT]; // Indexes counters for each bucket

    // Initialize bucket counts to 0
    for (int i = 0; i < BUCKET_COUNT; i++)
        bucketCount[i] = 0;

    // Find the maximum value in arr to determine how to distribute it into buckets
    int max = findMax(arr, n);
    float interval = (float)max / BUCKET_COUNT; 

    // Distribute array elements into buckets
    for (int i = 0; i < n; i++) {
        int idx = arr[i] / interval;
        if (idx >= BUCKET_COUNT) idx = BUCKET_COUNT - 1; // Cap to the last bucket
        // Place element in respective bucket
        bucket[idx][bucketCount[idx]++] = arr[i]; 
    }

    // Sort individual buckets and concatenate results
    int sortedIndex = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (bucketCount[i] > 0) {
            // Sort the individual bucket using simple insertion sort
            for (int j = 1; j < bucketCount[i]; j++) {
                int temp = bucket[i][j];
                int k = j - 1;
                while (k >= 0 && bucket[i][k] > temp) {
                    bucket[i][k + 1] = bucket[i][k];
                    k--;
                }
                bucket[i][k + 1] = temp;
            }
            // Now, add the sorted bucket to the result array
            for (int j = 0; j < bucketCount[i]; j++)
                arr[sortedIndex++] = bucket[i][j];
        }
    }
}

int main() {
    int n, i;

    // A riddle of sorts, how many numbers will we sort today?
    printf("Welcome to the Bucket Sort Puzzle! Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    int arr[n];

    // A magic of input, let’s gather these enchanting numbers!
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The array before sorting:\n");
    printArray(arr, n);

    // In haste, we sort them into oblivion!
    bucketSort(arr, n);

    printf("The array after sorting:\n");
    printArray(arr, n);

    return 0;
}