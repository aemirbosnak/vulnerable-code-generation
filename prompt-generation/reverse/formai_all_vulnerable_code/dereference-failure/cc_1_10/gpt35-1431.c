//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

/* Function to sort the given array using bucket sort */
void bucketSort(int arr[], int n)
{
    // Create an array of buckets
    int max_element = arr[0];
    int min_element = arr[0];
    int i, j, k;
    for (i = 1; i < n; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
        if (arr[i] < min_element) {
            min_element = arr[i];
        }
    }
    int bucket_size = 5;
    int num_buckets = (max_element - min_element + 1) / bucket_size + 1;
    int **buckets = (int **)calloc(num_buckets, sizeof(int *));

    for (i = 0; i < num_buckets; i++) {
        buckets[i] = (int *)calloc(bucket_size, sizeof(int));
    }

    // Store the elements in the buckets
    for (i = 0; i < n; i++) {
        int index = (arr[i] - min_element) / bucket_size;
        for (j = 0; j < bucket_size; j++) {
            if (buckets[index][j] == 0) {
                buckets[index][j] = arr[i];
                break;
            }
        }
    }

    // Sort the elements in each bucket using insertion sort
    for (i = 0; i < num_buckets; i++) {
        for (j = 1; j < bucket_size; j++) {
            int temp = buckets[i][j];
            k = j - 1;
            while ((temp < buckets[i][k]) && (k >= 0)) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = temp;
        }
    }

    // Concatenate the sorted buckets to get the final sorted array
    int index = 0;
    for (i = 0; i < num_buckets; i++) {
        for (j = 0; j < bucket_size; j++) {
            if (buckets[i][j] != 0) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    // Free memory
    for (i = 0; i < num_buckets; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

/* Function to print the sorted array */
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Main function */
int main()
{
    int arr[] = { 34, 45, 11, 23, 56, 8, 20, 35, 19, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}