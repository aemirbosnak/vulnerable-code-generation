//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to swap two elements */
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* Function to find the maximum value in an array */
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/* Function to perform bucket sort */
void bucketSort(int arr[], int n) {
    int max = findMax(arr, n);
    int bucketSize = max / n;
    int* buckets[n];

    /* Initialize each bucket with -1 */
    for (int i = 0; i < n; i++) {
        buckets[i] = (int*)malloc(bucketSize * sizeof(int));
        for (int j = 0; j < bucketSize; j++) {
            buckets[i][j] = -1;
        }
    }

    /* Insert each element into its corresponding bucket */
    for (int i = 0; i < n; i++) {
        int index = arr[i] / bucketSize;
        buckets[index][arr[i] % bucketSize] = arr[i];
    }

    /* Merge the buckets back into the original array */
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize; j++) {
            if (buckets[i][j]!= -1) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    /* Initialize the array with random values */
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    /* Print the unsorted array */
    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /* Sort the array using bucket sort */
    bucketSort(arr, n);

    /* Print the sorted array */
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}