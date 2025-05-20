//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Post-Apocalyptic Bucket Sort

void bucket_sort(int arr[], int n, int max_bucket_size) {
    int i, j, k;
    int *buckets[100]; // create an array of buckets, each with max_bucket_size elements

    // create buckets
    for (i = 0; i < 100; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * max_bucket_size); // allocate memory for each bucket
        memset(buckets[i], 0, sizeof(int) * max_bucket_size); // initialize each bucket to 0
    }

    // insert elements into buckets
    for (i = 0; i < n; i++) {
        j = arr[i] % max_bucket_size; // calculate the bucket index
        buckets[j][j/max_bucket_size] += 1; // increment the count for the current element in the bucket
    }

    // merge elements from buckets back into the array
    for (i = 0; i < 100; i++) {
        for (j = 0; j < max_bucket_size; j++) {
            if (buckets[i][j] > 0) {
                arr[j] = i; // assign the bucket index as the new position for the element
                buckets[i][j] -= 1; // decrement the count in the bucket
            }
        }
    }

    // free allocated memory
    for (i = 0; i < 100; i++) {
        free(buckets[i]); // free each bucket
    }
}

int main() {
    int arr[] = { 9, 3, 6, 1, 8, 5, 2, 7, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_bucket_size = 10;

    bucket_sort(arr, n, max_bucket_size);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}