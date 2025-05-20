//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

void bucket_sort(int* arr, int size) {
    int i, j;
    int* bucket[MAX_RANGE];
    int range = MAX_RANGE / size;
    int max_val = 0;

    for (i = 0; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    for (i = 0; i < MAX_RANGE; i++) {
        bucket[i] = (int*) malloc(sizeof(int) * size);
    }

    for (i = 0; i < size; i++) {
        j = (arr[i] * MAX_RANGE) / max_val;
        bucket[j][i / range] = arr[i];
    }

    for (i = 0; i < size; i++) {
        arr[i] = bucket[arr[i] * MAX_RANGE / max_val][i / range];
    }

    for (i = 0; i < MAX_RANGE; i++) {
        free(bucket[i]);
    }
}

int main() {
    int size;
    int* arr;
    int i;

    srand(time(NULL));
    size = rand() % MAX_SIZE + 1;
    arr = (int*) malloc(sizeof(int) * size);

    for (i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }

    printf("Before Sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, size);

    printf("\nAfter Sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}