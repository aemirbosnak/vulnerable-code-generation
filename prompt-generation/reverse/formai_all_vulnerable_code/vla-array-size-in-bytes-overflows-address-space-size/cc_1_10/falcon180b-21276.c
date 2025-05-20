//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

void bucket_sort(int arr[], int n) {
    int i, j, max_val, min_val;
    int *bucket[MAX_VALUE];

    // create empty buckets
    for (i = 0; i < MAX_VALUE; i++) {
        bucket[i] = NULL;
    }

    // find the range of the array
    max_val = arr[0];
    min_val = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    // compute the bucket size
    int bucket_size = (max_val - min_val + 1) / n;

    // place each element in its corresponding bucket
    for (i = 0; i < n; i++) {
        j = (arr[i] - min_val) / bucket_size;
        if (bucket[j] == NULL) {
            bucket[j] = malloc(sizeof(int));
        }
        int *temp = bucket[j];
        while (*temp!= -1) {
            temp++;
        }
        *temp = arr[i];
    }

    // concatenate the sorted buckets back into the original array
    int k = 0;
    for (i = 0; i < MAX_VALUE; i++) {
        if (bucket[i]!= NULL) {
            while (*bucket[i]!= -1) {
                arr[k++] = *bucket[i]++;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];

    // generate a random array of integers
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VALUE;
    }

    // print the unsorted array
    printf("Unsorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // sort the array using bucket sort
    bucket_sort(arr, n);

    // print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}