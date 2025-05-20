//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void bucket_sort(int array[], int size) {
    int i, j, k;
    int min_val = array[0], max_val = array[0];

    // Find the maximum and minimum values in the array
    for (i = 1; i < size; i++) {
        if (array[i] < min_val)
            min_val = array[i];
        else if (array[i] > max_val)
            max_val = array[i];
    }

    int bucket_count = (max_val - min_val) / BUCKET_SIZE + 1;
    int **buckets = (int **)malloc(bucket_count * sizeof(int *));

    // initialize the buckets
    for (i = 0; i < bucket_count; i++) {
        buckets[i] = (int *)malloc(BUCKET_SIZE * sizeof(int));
        k = 0;
        for (j = 0; j < BUCKET_SIZE; j++)
            buckets[i][j] = 0;
    }

    // put the values in the buckets
    for (i = 0; i < size; i++) {
        int pos = (array[i] - min_val) / BUCKET_SIZE;
        buckets[pos][k++] = array[i];
    }

    // sort the values in each bucket
    for (i = 0; i < bucket_count; i++) {
        for (j = 1; j < BUCKET_SIZE; j++) {
            int key = buckets[i][j];
            int l = j - 1;
            while (l >= 0 && buckets[i][l] > key) {
                buckets[i][l + 1] = buckets[i][l];
                l--;
            }
            buckets[i][l + 1] = key;
        }
    }

    // concatenate the sorted buckets into the final array
    k = 0;
    for (i = 0; i < bucket_count; i++) {
        for (j = 0; j < BUCKET_SIZE; j++) {
            if (buckets[i][j] != 0)
                array[k++] = buckets[i][j];
        }
    }

    // free the buckets
    for (i = 0; i < bucket_count; i++)
        free(buckets[i]);
    free(buckets);
}

int main() {
    int i;
    int array[] = { 4, 2, 10, 7, 9, 3, 1, 8, 5, 6 };
    int size = sizeof(array) / sizeof(int);

    printf("Unsorted Array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    bucket_sort(array, size);

    printf("\nSorted Array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
    return 0;
}