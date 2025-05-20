//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUCKETS 10 // Maximum number of buckets
#define MAX_VALUE 100 // Maximum value that can be sorted

// Function to get the index of the bucket for a value
int getBucketIndex(int value) {
    return value * MAX_BUCKETS / (MAX_VALUE + 1);
}

// Function to perform the bucket sort
void bucketSort(int arr[], int n) {
    // Create buckets
    int **buckets = (int **)malloc(MAX_BUCKETS * sizeof(int *));
    int *bucketSizes = (int *)calloc(MAX_BUCKETS, sizeof(int));
    
    for(int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }

    // Distribute the input values into buckets
    for(int i = 0; i < n; i++) {
        int index = getBucketIndex(arr[i]);
        buckets[index][bucketSizes[index]++] = arr[i];
    }

    // Sort individual buckets and concatenate them
    int index = 0;
    for(int i = 0; i < MAX_BUCKETS; i++) {
        if(bucketSizes[i] > 0) {
            // Temporary array for sorting
            int *temp = (int *)malloc(bucketSizes[i] * sizeof(int));
            for(int j = 0; j < bucketSizes[i]; j++) {
                temp[j] = buckets[i][j];
            }
            // Perform insertion sort on the temporary array
            for(int j = 1; j < bucketSizes[i]; j++) {
                int key = temp[j];
                int k = j - 1;
                while(k >= 0 && temp[k] > key) {
                    temp[k + 1] = temp[k];
                    k--;
                }
                temp[k + 1] = key;
            }
            // Place sorted elements back into original array
            for(int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = temp[j];
            }
            free(temp);
        }
    }

    // Clean up
    for (int i = 0; i < MAX_BUCKETS; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to print the array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nHappy sorting completed! 🎉\n");
}

// Main function
int main() {
    int n;
    printf("Welcome to Bucket Sort! 🎉\n");
    printf("How many numbers do you want to sort? ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Please enter %d numbers (between 0 and %d):\n", n, MAX_VALUE);
    for(int i = 0; i < n; i++) {
        do {
            scanf("%d", &arr[i]);
            if (arr[i] < 0 || arr[i] > MAX_VALUE) {
                printf("Oops! Please enter a number between 0 and %d: ", MAX_VALUE);
            }
        } while (arr[i] < 0 || arr[i] > MAX_VALUE);
    }

    printf("You entered: ");
    printArray(arr, n);

    // Perform bucket sort!
    bucketSort(arr, n);

    printf("Sorted array is: ");
    printArray(arr, n);

    free(arr);
    printf("Thank you for using the Bucket Sort program! Have a great day! 🌈\n");
    return 0;
}