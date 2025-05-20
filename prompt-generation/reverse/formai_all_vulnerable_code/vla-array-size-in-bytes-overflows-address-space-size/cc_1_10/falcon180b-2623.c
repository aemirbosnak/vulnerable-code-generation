//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define RANGE 100

void bucket_sort(int arr[], int n) {
    int i, j, k;
    int count[RANGE] = { 0 };
    int *bucket[RANGE];

    // Initialize buckets
    for (i = 0; i < RANGE; i++) {
        bucket[i] = (int *) malloc(n * sizeof(int));
    }

    // Distribute elements into buckets
    for (i = 0; i < n; i++) {
        k = arr[i] / RANGE;
        count[k]++;
        bucket[k][count[k] - 1] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < RANGE; i++) {
        for (j = 0; j < count[i]; j++) {
            k = j;
            while (k > 0 && bucket[i][k - 1] > bucket[i][k]) {
                int temp = bucket[i][k - 1];
                bucket[i][k - 1] = bucket[i][k];
                bucket[i][k] = temp;
                k--;
            }
        }
    }

    // Merge buckets back into original array
    for (i = 0; i < n; i++) {
        arr[i] = bucket[arr[i] / RANGE][i % count[arr[i] / RANGE]];
    }

    // Free memory
    for (i = 0; i < RANGE; i++) {
        free(bucket[i]);
    }
}

void generate_array(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX;
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    generate_array(arr, n);

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}