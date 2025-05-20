//FormAI DATASET v1.0 Category: Benchmarking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 5000000
#define MAX_VALUE 100000

void quicksort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    if (left < j) {
        quicksort(arr, left, j);
    }
    if (i < right) {
        quicksort(arr, i, right);
    }
}

int main() {
    int i;
    int *arr = (int*) malloc(ARRAY_SIZE * sizeof(int));
    clock_t start, end;
    double cpu_time_used;

    srand(time(NULL));

    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % MAX_VALUE;
    }

    start = clock();
    quicksort(arr, 0, ARRAY_SIZE - 1);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Quicksort took %f seconds to execute.\n", cpu_time_used);

    free(arr);
    return 0;
}