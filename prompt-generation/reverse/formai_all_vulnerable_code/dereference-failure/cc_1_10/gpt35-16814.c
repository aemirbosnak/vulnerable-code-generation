//FormAI DATASET v1.0 Category: Benchmarking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int *arr, int start, int end) {
    if (start < end) {
        int pivot = partition(arr, start, end);
        quicksort(arr, start, pivot-1);
        quicksort(arr, pivot+1, end);
    }
}

int partition(int *arr, int start, int end) {
    int pivot = arr[end];
    int i = start-1;

    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;

    return i+1;
}

void insertion_sort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i-1;
    
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
    
        arr[j+1] = key;
    }
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int size = 100000;
    int *arr = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000000;
    }

    printf("Unsorted array: ");
    print_array(arr, size);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    insertion_sort(arr, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion sort time taken: %f seconds\n", cpu_time_used);

    printf("Sorted array: ");
    print_array(arr, size);

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000000;
    }

    printf("Unsorted array: ");
    print_array(arr, size);

    start = clock();
    quicksort(arr, 0, size-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quick sort time taken: %f seconds\n", cpu_time_used);

    printf("Sorted array: ");
    print_array(arr, size);

    free(arr);
    return 0;
}