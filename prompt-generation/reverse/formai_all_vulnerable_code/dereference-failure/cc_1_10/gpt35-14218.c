//FormAI DATASET v1.0 Category: Benchmarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int array_size = 100000;
    
    // Generate random integers for array
    int* array = malloc(sizeof(int) * array_size);
    for (int i = 0; i < array_size; i++) {
        array[i] = rand() % 1000;
    }
    
    // Bubble sort algorithm
    clock_t start_bubble = clock();
    for (int i = 0; i < array_size; i++) {
        for (int j = 0; j < array_size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
    clock_t end_bubble = clock();
    double time_bubble = ((double)(end_bubble - start_bubble)) / CLOCKS_PER_SEC;
    
    // Quick sort algorithm
    int pivot, pivot_index, left, right;
    void quicksort(int[], int, int);
    clock_t start_quick = clock();
    quicksort(array, 0, array_size-1);
    clock_t end_quick = clock();
    double time_quick = ((double)(end_quick - start_quick)) / CLOCKS_PER_SEC;
    
    // Print time results
    printf("Bubble Sort Time: %f seconds\n", time_bubble);
    printf("Quick Sort Time: %f seconds\n", time_quick);
    printf("Quick sort is %.2f times faster than bubble sort.\n", time_bubble/time_quick);

    return 0;
}

void quicksort(int array[], int left, int right) {
    if (left < right) {
        int pivot_index = (left + right) / 2;
        int pivot = array[pivot_index];
        int i = left - 1;
        int j = right + 1;
        
        while (1) {
            while (array[++i] < pivot);
            while (array[--j] > pivot);
            if (i >= j) {
                break;
            }
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        quicksort(array, left, i-1);
        quicksort(array, j+1, right);
    }
}