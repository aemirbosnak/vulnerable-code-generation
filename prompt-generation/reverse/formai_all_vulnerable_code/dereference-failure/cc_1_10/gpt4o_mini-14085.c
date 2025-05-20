//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VALUE 100
#define BUCKET_COUNT 10  // Number of buckets
#define MAX_NUMBERS 100  // Maximum number of input values

// Function to create and initialize buckets
int **createBuckets() {
    int **buckets = malloc(BUCKET_COUNT * sizeof(int *));
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = malloc(MAX_NUMBERS * sizeof(int));
    }
    return buckets;
}

// Function to free allocated buckets memory
void freeBuckets(int **buckets) {
    for (int i = 0; i < BUCKET_COUNT; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

// Function to insert elements into the appropriate bucket
void bucketInsert(int *arr, int n, int **buckets, int *bucketSizes) {
    for (int i = 0; i < n; i++) {
        int index = arr[i] * BUCKET_COUNT / (MAX_VALUE + 1); // Bucket index
        buckets[index][bucketSizes[index]++] = arr[i];
    }
}

// Function to sort individual buckets using a simple sorting algorithm
void insertionSort(int *bucket, int n) {
    for (int i = 1; i < n; i++) {
        int key = bucket[i];
        int j = i - 1;
        
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to concatenate sorted buckets into the original array
void bucketSort(int *arr, int n) {
    int **buckets = createBuckets();  // Create the buckets!
    int *bucketSizes = calloc(BUCKET_COUNT, sizeof(int));  // Size of each bucket

    // Insert elements into buckets
    bucketInsert(arr, n, buckets, bucketSizes);

    // Sort the buckets and concatenate back to the original array
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    // Free the allocated memory for buckets and their sizes
    freeBuckets(buckets);
    free(bucketSizes);
}

// Function to print the array happily
void printArray(int *arr, int n) {
    printf("Here's your sorted array with a sprinkle of joy:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("✨🎉\n");
}

// Main function to kick off the fun!
int main() {
    int n;
    printf("🎈 Welcome to the cheerful Bucket Sort program! 🎈\n");
    printf("How many numbers would you like to sort? (max %d) ", MAX_NUMBERS);
    scanf("%d", &n);

    if (n > MAX_NUMBERS) {
        printf("Oops! Please enter a value less than or equal to %d. 😅\n", MAX_NUMBERS);
        return 1;
    }

    int arr[MAX_NUMBERS];
    printf("Great! Please enter %d numbers (0 to %d):\n", n, MAX_VALUE);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] < 0 || arr[i] > MAX_VALUE) {
            printf("😱 Please ensure all numbers are between 0 and %d!\n", MAX_VALUE);
            return 1;
        }
    }

    printf("Sorting your numbers... 🎶\n");

    // Call the bucket sort function
    bucketSort(arr, n);

    // Rejoice and print the sorted array
    printArray(arr, n);

    printf("Thank you for using the cheerful Bucket Sort! ✌️😄 Until next time!\n");
    return 0;
}