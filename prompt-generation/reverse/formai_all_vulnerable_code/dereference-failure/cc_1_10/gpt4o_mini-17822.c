//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        int temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }
}

void insertion_sort(int *array, int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void fill_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000; // Random numbers between 0-999
    }
}

void benchmark_sort(void (*sort_func)(int*, int), int *array, int size) {
    clock_t start, end;
    start = clock();
    sort_func(array, size);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by %s: %f seconds\n", (void*)(sort_func), time_taken);
}

int main() {
    int size;
    printf("Welcome to the Sorting Benchmark Program!\n");
    printf("Let's find out which sorting algorithm is the fastest.\n");
    printf("Please enter the size of the array to be sorted (e.g., 1000): ");
    scanf("%d", &size);

    // Generating random input array for each sort
    int *array1 = (int*) malloc(size * sizeof(int));
    int *array2 = (int*) malloc(size * sizeof(int));
    int *array3 = (int*) malloc(size * sizeof(int));

    fill_array(array1, size);
    for (int i = 0; i < size; i++) array2[i] = array1[i]; // Copy for other sorts
    for (int i = 0; i < size; i++) array3[i] = array1[i]; // Copy for other sorts

    printf("Benchmarking Sorting Algorithms...\n");

    printf("Bubble Sort: \n");
    benchmark_sort(bubble_sort, array1, size);

    printf("Selection Sort: \n");
    benchmark_sort(selection_sort, array2, size);

    printf("Insertion Sort: \n");
    benchmark_sort(insertion_sort, array3, size);

    // Clean up dynamic memory
    free(array1);
    free(array2);
    free(array3);

    printf("Thank you for using the Sorting Benchmark Program! Feel free to modify the array size or add more algorithms to test!\n");
    return 0;
}