//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void bucketSort(float arr[], int n);
void insertionSort(float arr[], int n);
void printArray(float arr[], int n);

int main() {
    // Let's cheerily greet our users!
    printf("🎉 Welcome to the Cheerful Bucket Sort Program! 🎉\n");
    
    // Let's prepare some data to sort
    int n;
    printf("How many floating-point numbers would you like to sort? ");
    scanf("%d", &n);
    
    float *arr = (float*)malloc(n * sizeof(float));
    
    // Let's fill our array with some happy floating-point numbers!
    printf("Please input your %d cheerful numbers (between 0.0 and 1.0): \n", n);
    for (int i = 0; i < n; i++) {
        printf("Number %d: ", i + 1);
        scanf("%f", &arr[i]);
    }
    
    printf("\nYou entered: \n");
    printArray(arr, n);
    
    // Time to sort! 🎈
    bucketSort(arr, n);
    
    // Let's celebrate and print the sorted array!
    printf("\n🎊 Your sorted cheerful numbers are: \n");
    printArray(arr, n);
    
    // Free the allocated memory because we are responsible citizens
    free(arr);
    
    // A happy farewell
    printf("\n🥳 Thank you for using the Cheerful Bucket Sort Program! Goodbye! 🥳\n");

    return 0;
}

// Function to sort the array using bucket sort
void bucketSort(float arr[], int n) {
    // Create an array of buckets
    int bucketCount = 10; // Feel free to adjust this bucket count!
    int i, j;

    // Create buckets and initialize them
    float **buckets = (float**)malloc(bucketCount * sizeof(float*));
    int *bucketSizes = (int*)malloc(bucketCount * sizeof(int));

    for (i = 0; i < bucketCount; i++) {
        buckets[i] = (float*)malloc(n * sizeof(float));
        bucketSizes[i] = 0;
    }

    // Place each number into its corresponding bucket
    for (i = 0; i < n; i++) {
        int index = (int)(arr[i] * bucketCount);
        if (index == bucketCount) { // Handle 1.0 case
            index--;
        }
        buckets[index][bucketSizes[index]++] = arr[i];
    }

    // Sort each bucket and concatenate them
    int pos = 0;
    for (i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            // Sort the current bucket
            insertionSort(buckets[i], bucketSizes[i]);
            // Concatenate the sorted bucket to the output array
            for (j = 0; j < bucketSizes[i]; j++) {
                arr[pos++] = buckets[i][j];
            }
        }
    }

    // Free buckets because we don't need them anymore
    for (i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Simple insertion sort implementation
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        // Move elements that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print the array cheerfully
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}