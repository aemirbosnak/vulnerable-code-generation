//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000
#define MAX_RANGE 1000

int *array;
int size;

void init_array(int n) {
    array = (int*)malloc(n * sizeof(int));
    size = n;
    for (int i = 0; i < n; i++) {
        array[i] = rand() % MAX_RANGE;
    }
}

void print_array() {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void bucket_sort(int *arr, int n, int max_range) {
    int range = max_range / n;
    int bucket[n];
    for (int i = 0; i < n; i++) {
        bucket[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        bucket[(arr[i] / range)]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            arr[j * range + i * range] = i * range;
        }
    }
}

int main() {
    srand(time(NULL));
    int n = MAX_SIZE;
    init_array(n);
    printf("Original Array:\n");
    print_array();
    bucket_sort(array, n, MAX_RANGE);
    printf("Sorted Array:\n");
    print_array();
    return 0;
}