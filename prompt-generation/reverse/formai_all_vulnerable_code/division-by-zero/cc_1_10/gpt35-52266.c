//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int *arr, int size) {
    // Find maximum and minimum elements in the array
    int max = arr[0];
    int min = arr[0];
    for (int i=0; i<size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        } else if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range of each bucket
    int range = (max - min) / size + 1;

    // Create buckets
    int **buckets = malloc(size * sizeof(int *));
    for (int i=0; i<size; i++) {
        buckets[i] = malloc(range * sizeof(int));
    }
    for (int i=0; i<size; i++) {
        int index = (arr[i] - min) / range;
        buckets[index][i] = arr[i];
    }

    // Sort buckets
    for (int i=0; i<size; i++) {
        int bucketSize = 0;
        while (buckets[i][bucketSize] != 0) {
            bucketSize++;
        }
        for (int j=1; j<bucketSize; j++) {
            int temp = buckets[i][j];
            int k = j-1;
            while (k >= 0 && temp < buckets[i][k]) {
                buckets[i][k+1] = buckets[i][k];
                k--;
            }
            buckets[i][k+1] = temp;
        }
    }

    // Combine buckets
    int index = 0;
    for (int i=0; i<size; i++) {
        for (int j=0; j<range; j++) {
            if (buckets[i][j] != 0) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    // Free memory
    for (int i=0; i<size; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    printf("Welcome to the energetic Bucket Sort implementation program!\n");
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));
    printf("Enter %d integers: \n", size);
    for (int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before sorting: ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, size);

    printf("After sorting: ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    printf("Thank you for using the energetic Bucket Sort implementation program!\n");
    return 0;
}