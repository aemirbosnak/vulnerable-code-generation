//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int data;
    int bucket;
} BucketElement;

void sort_buckets(BucketElement *array, int size) {
    int i;
    for (i = 0; i < ceil(sqrt(size)); i++) {
        int j;
        for (j = 0; j < size; j++) {
            if (array[j].bucket == i) {
                array[j].bucket = i * 10;
            }
        }
    }
}

void bucket_sort(int *array, int size) {
    int i, j;
    BucketElement *buckets = (BucketElement*)malloc(sizeof(BucketElement) * size);

    for (i = 0; i < size; i++) {
        int bucket = floor(log10(array[i])) + 1;
        buckets[bucket].data = array[i];
        buckets[bucket].bucket = bucket;
    }

    sort_buckets(buckets, size);

    int count = 0;
    int k;
    for (k = 0; k < size; k++) {
        array[count] = buckets[k].data;
        count++;
    }
    free(buckets);
}

int main() {
    int size = 10;
    int *array = (int*)malloc(sizeof(int) * size);
    int i;
    for (i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    printf("Original array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    bucket_sort(array, size);

    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}