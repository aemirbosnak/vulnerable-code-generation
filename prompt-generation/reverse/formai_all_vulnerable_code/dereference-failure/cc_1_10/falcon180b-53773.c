//Falcon-180B DATASET v1.0 Category: Sorting ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} Array;

void init(Array *arr, int size) {
    arr->data = (int *)malloc(size * sizeof(int));
    arr->size = size;
}

void destroy(Array *arr) {
    free(arr->data);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(Array *arr, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int temp[MAX_SIZE];

    while (i <= mid && j <= right) {
        if (arr->data[i] < arr->data[j]) {
            temp[k++] = arr->data[i++];
        } else {
            temp[k++] = arr->data[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr->data[i++];
    }

    while (j <= right) {
        temp[k++] = arr->data[j++];
    }

    for (i = left; i <= right; i++) {
        arr->data[i] = temp[i - left];
    }
}

void mergeSort(Array *arr, int left, int right) {
    int mid;

    if (left < right) {
        mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    Array arr;
    int i, n;

    srand(time(NULL));
    n = rand() % MAX_SIZE + 1;

    init(&arr, n);

    for (i = 0; i < n; i++) {
        arr.data[i] = rand() % 100;
    }

    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr.data[i]);
    }

    mergeSort(&arr, 0, n - 1);

    printf("\nAfter sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr.data[i]);
    }

    destroy(&arr);

    return 0;
}