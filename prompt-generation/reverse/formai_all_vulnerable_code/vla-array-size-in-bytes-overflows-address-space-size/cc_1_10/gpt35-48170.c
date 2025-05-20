//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform bucket sort
void bucketSort(int arr[], int n, int k)
{
    // Create an array of buckets
    int buckets[k];

    // Initialize all buckets to 0
    for(int i = 0; i < k; i++) {
        buckets[i] = 0;
    }

    // Store the frequency of elements in each bucket
    for(int i = 0; i < n; i++) {
        buckets[arr[i]]++;
    }

    // Sort the elements in each bucket and update the original array
    int index = 0;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < buckets[i]; j++) {
            arr[index++] = i;
        }
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    printf("[ ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// The main function
int main()
{
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the futuristic bucket sort implementation!\n");

    int n, k;
    printf("Enter the size of the array to be sorted: ");
    scanf("%d", &n);

    printf("Enter the range of values in the array (0 to k): ");
    scanf("%d", &k);

    int arr[n];

    // Generate random elements for the array
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % (k + 1);
    }

    printf("Unsorted Array: ");
    printArray(arr, n);

    bucketSort(arr, n, k);

    printf("Sorted Array: ");
    printArray(arr, n);

    printf("Thank you for using the futuristic bucket sort implementation!\n");

    return 0;
}