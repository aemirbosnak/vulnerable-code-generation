//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000
#define BUCKET_SIZE 10

typedef struct {
    int *arr;
    int size;
} bucket;

void create_buckets(int size) {
    int i;
    bucket *b = (bucket *)malloc(size * sizeof(bucket));
    for (i = 0; i < size; i++) {
        b[i].arr = (int *)malloc(BUCKET_SIZE * sizeof(int));
        b[i].size = 0;
    }
}

void bucket_sort(int *arr, int size) {
    int i, j, min, max, range;
    bucket *b = (bucket *)malloc(size * sizeof(bucket));
    create_buckets(size);

    range = (int)ceil((double)size / BUCKET_SIZE);

    for (i = 0; i < size; i++) {
        min = (int)ceil((double)arr[i] / range);
        max = (int)floor((double)arr[i] / range);
        for (j = min; j <= max; j++) {
            if (b[j].size == BUCKET_SIZE) {
                printf("Bucket %d is full\n", j);
            } else {
                b[j].arr[b[j].size++] = arr[i];
            }
        }
    }

    i = 0;
    for (j = 0; j < size; j++) {
        if (b[j].size > 0) {
            memcpy(&arr[i], b[j].arr, b[j].size * sizeof(int));
            i += b[j].size;
        }
    }

    free(b);
}

int main() {
    int size, i;
    int *arr;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));

    printf("Enter the elements of the array: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, size);

    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}