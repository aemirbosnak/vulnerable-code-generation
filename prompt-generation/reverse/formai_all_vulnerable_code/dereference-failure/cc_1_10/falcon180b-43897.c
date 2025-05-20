//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bucket_sort(int arr[], int n) {
    int i, j, max, min, range, *bucket[MAX_SIZE];

    // Find the range of the array
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range of each bucket
    range = (max - min) / n;

    // Create an empty bucket for each range
    for (i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(sizeof(int));
    }

    // Place the elements in the appropriate bucket
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / range;
        if (bucket[j] == NULL) {
            bucket[j] = (int *)malloc(sizeof(int));
        }
        int *temp = (int *)realloc(bucket[j], sizeof(int) * (1 + *(int *)bucket[j]));
        if (temp == NULL) {
            printf("Memory error\n");
            exit(0);
        }
        bucket[j] = temp;
        *(int *)(temp + *(int *)bucket[j]) = arr[i];
        *(int *)bucket[j] += 1;
    }

    // Combine the sorted buckets
    i = 0;
    for (j = 0; j < n; j++) {
        if (bucket[j]!= NULL) {
            while (*(int *)bucket[j] > 0) {
                arr[i++] = *(int *)(bucket[j]);
                *(int *)bucket[j] -= 1;
            }
            free(bucket[j]);
        }
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Declare an array of integers
    int arr[n];

    // Fill the array with random integers
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    // Print the original array
    printf("Original array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using bucket sort
    bucket_sort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}