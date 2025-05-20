//FormAI DATASET v1.0 Category: Benchmarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void fill_array(int *arr) {
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % ARRAY_SIZE;
    }
}

void bubble_sort(int *arr) {
    int i, j, temp;
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void quick_sort(int *arr, int left, int right) {
    int i, j, pivot, temp;
    if (left < right) {
        i = left;
        j = right;
        pivot = arr[left + (rand() % (right - left + 1))];

        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }

        if (left < j) {
            quick_sort(arr, left, j);
        }
        if (i < right) {
            quick_sort(arr, i, right);
        }
    }
}

int main() {
    int *arr = (int *) malloc(ARRAY_SIZE * sizeof(int));

    srand(time(NULL));
    fill_array(arr);

    clock_t start, end;

    // Bubble Sort
    start = clock();
    bubble_sort(arr);
    end = clock();
    printf("Bubble Sort Time: %lf seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    // Quick Sort
    fill_array(arr); // Reset Array
    start = clock();
    quick_sort(arr, 0, ARRAY_SIZE - 1);
    end = clock();
    printf("Quick Sort Time: %lf seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}