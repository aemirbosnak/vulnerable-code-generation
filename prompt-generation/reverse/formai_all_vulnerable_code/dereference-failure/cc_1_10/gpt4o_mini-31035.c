//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void fill_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

void bubble_sort(int *array, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void merge(int *array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int *array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

void run_benchmark(void (*sort_func)(int*, size_t), int *array, size_t size) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sort_func(array, size);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);
}

int main() {
    srand(time(NULL));
    
    int *array_bubble = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int *array_merge = (int *)malloc(ARRAY_SIZE * sizeof(int));

    fill_array(array_bubble, ARRAY_SIZE);
    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        array_merge[i] = array_bubble[i];  // Copying elements for merge sort
    }
    
    printf("Benchmarking Bubble Sort:\n");
    run_benchmark(bubble_sort, array_bubble, ARRAY_SIZE);
    
    printf("Benchmarking Merge Sort:\n");
    run_benchmark(merge_sort, array_merge, ARRAY_SIZE - 1);  // Merge sort requires (right = size - 1)

    free(array_bubble);
    free(array_merge);

    return 0;
}