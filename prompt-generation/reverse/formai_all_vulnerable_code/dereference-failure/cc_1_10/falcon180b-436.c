//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int size;
} Array;

Array create_array(int size) {
    Array arr;
    arr.arr = (int*) malloc(size * sizeof(int));
    arr.size = size;
    return arr;
}

void destroy_array(Array arr) {
    free(arr.arr);
}

void swap(Array arr, int i, int j) {
    int temp = arr.arr[i];
    arr.arr[i] = arr.arr[j];
    arr.arr[j] = temp;
}

int partition(Array arr, int low, int high) {
    int pivot = arr.arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr.arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

void quick_sort(Array arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    Array arr = create_array(n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr.arr[i]);
    }

    quick_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr.arr[i]);
    }
    printf("\n");

    destroy_array(arr);

    return 0;
}