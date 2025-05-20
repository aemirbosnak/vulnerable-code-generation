//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        j = rand() % n;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int partition(int *arr, int left, int right) {
    int pivot = arr[left];
    int i = left + 1;
    for (int j = left + 1; j <= right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[left], arr[i - 1]);
    return i - 1;
}

void quicksort(int *arr, int left, int right) {
    int pivot;
    if (left < right) {
        pivot = partition(arr, left, right);
        quicksort(arr, left, pivot - 1);
        quicksort(arr, pivot + 1, right);
    }
}

int main() {
    srand(time(NULL));
    int arr[10] = {4, 2, 7, 1, 3, 6, 5, 8, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}