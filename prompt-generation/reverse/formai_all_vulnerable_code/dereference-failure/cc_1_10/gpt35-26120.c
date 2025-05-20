//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Bucket {
    int count;
    int* values;
};

void bucketSort(int arr[], int n) {
    struct Bucket* buckets = malloc(sizeof(struct Bucket) * SIZE);

    for (int i = 0; i < SIZE; i++) {
        buckets[i].count = 0;
        buckets[i].values = NULL;
    }

    for (int i = 0; i < n; i++) {
        int index = arr[i] / SIZE;
        if (index >= SIZE) {
            index = SIZE - 1;
        }

        buckets[index].count++;
        buckets[index].values = realloc(buckets[index].values, buckets[index].count * sizeof(int));
        buckets[index].values[buckets[index].count - 1] = arr[i];
    }

    int k = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            arr[k++] = buckets[i].values[j];
        }
        free(buckets[i].values);
    }
    free(buckets);
}

int main() {
    int arr[] = { 52, 38, 98, 12, 4, 77, 29, 72, 65, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\n\nArray after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}