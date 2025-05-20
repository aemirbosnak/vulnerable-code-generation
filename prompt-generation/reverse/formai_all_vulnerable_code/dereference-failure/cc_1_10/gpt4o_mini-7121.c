//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

void generate_random_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10000;  // Random number between 0 and 9999
    }
}

void bubble_sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            // Swap array[i] and array[j]
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    // Swap array[i + 1] and array[high] (or pivot)
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}

void quicksort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

void merge(int *array, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

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

double benchmark_sort(void (*sort_func)(int *, int), int *array, int size) {
    clock_t start_time = clock();
    sort_func(array, size);
    clock_t end_time = clock();
    return ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
}

void print_results(const char *sort_name, double time_taken) {
    printf("%s took %.6f seconds to sort the array of size %d\n", sort_name, time_taken, SIZE);
}

int main() {
    srand(time(0));  // Seed for random number generation

    int *array_bubble = (int *)malloc(SIZE * sizeof(int));
    int *array_quick = (int *)malloc(SIZE * sizeof(int));
    int *array_merge = (int *)malloc(SIZE * sizeof(int));

    generate_random_array(array_bubble, SIZE);
    for (int i = 0; i < SIZE; i++) array_quick[i] = array_bubble[i];
    for (int i = 0; i < SIZE; i++) array_merge[i] = array_bubble[i];

    double bubble_time = benchmark_sort(bubble_sort, array_bubble, SIZE);
    print_results("Bubble Sort", bubble_time);

    double quick_time = benchmark_sort(quicksort, array_quick, SIZE - 1);
    print_results("Quicksort", quick_time);

    double merge_time = benchmark_sort(merge_sort, array_merge, SIZE - 1);
    print_results("Merge Sort", merge_time);

    free(array_bubble);
    free(array_quick);
    free(array_merge);

    return 0;
}