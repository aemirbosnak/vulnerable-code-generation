//FormAI DATASET v1.0 Category: Benchmarking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int *generate_random_array(int size) {
    int *array = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand();
    }
    return array;
}

void bubble_sort(int *array, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void quick_sort(int *array, int left, int right) {
    int pivot, temp, i, j;
    if (left < right) {
        pivot = left;
        i = left;
        j = right;
        while (i < j) {
            while (array[i] <= array[pivot] && i < right)
                i++;
            while (array[j] > array[pivot])
                j--;
            if (i < j) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        temp = array[pivot];
        array[pivot] = array[j];
        array[j] = temp;
        quick_sort(array, left, j - 1);
        quick_sort(array, j + 1, right);
    }
}

void merge(int *array, int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
 
    int *left_array = (int *) malloc(n1 * sizeof(int));
    int *right_array = (int *) malloc(n2 * sizeof(int));
 
    for (i = 0; i < n1; i++)
        left_array[i] = array[left + i];
    for (j = 0; j < n2; j++)
        right_array[j] = array[middle + 1+ j];
 
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (left_array[i] <= right_array[j]) {
            array[k] = left_array[i];
            i++;
        }
        else {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        array[k] = left_array[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        array[k] = right_array[j];
        j++;
        k++;
    }
    
    free(left_array);
    free(right_array);
}

void merge_sort(int *array, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        merge_sort(array, left, middle);
        merge_sort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

void run_benchmark(int size) {
    printf("Generating random array of size %d\n", size);
    int *array = generate_random_array(size);

    printf("Sorting with Bubble Sort...\n");
    clock_t start_time = clock();
    bubble_sort(array, size);
    clock_t end_time = clock();
    double bubble_sort_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Sorting with Quick Sort...\n");
    start_time = clock();
    quick_sort(array, 0, size - 1);
    end_time = clock();
    double quick_sort_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Sorting with Merge Sort...\n");
    start_time = clock();
    merge_sort(array, 0, size - 1);
    end_time = clock();
    double merge_sort_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Bubble Sort Time: %f seconds\n", bubble_sort_time);
    printf("Quick Sort Time: %f seconds\n", quick_sort_time);
    printf("Merge Sort Time: %f seconds\n", merge_sort_time);

    free(array);
}

int main() {
    run_benchmark(ARRAY_SIZE);
    return 0;
}