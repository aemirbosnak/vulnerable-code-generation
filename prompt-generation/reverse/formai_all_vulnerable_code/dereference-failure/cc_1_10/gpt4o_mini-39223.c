//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100000
#define MAX_VAL 1000

void generate_random_array(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void quick_sort(int *array, int low, int high);
int partition(int *array, int low, int high);
void print_array(int *array, size_t size);
double benchmark_sort(void (*sort_func)(int *, size_t), int *array, size_t size);

int main() {
    int *array1 = (int *)malloc(N * sizeof(int));
    int *array2 = (int *)malloc(N * sizeof(int));
    
    if (array1 == NULL || array2 == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Generate a random array for both sorting algorithms
    generate_random_array(array1, N);
    for (size_t i = 0; i < N; i++) {
        array2[i] = array1[i]; // Copy to second array for fairness
    }

    // Benchmark Bubble Sort
    double bubble_time = benchmark_sort(bubble_sort, array1, N);
    printf("Bubble Sort took: %f seconds\n", bubble_time);

    // Benchmark Quick Sort
    double quick_time = benchmark_sort(quick_sort, array2, N);
    printf("Quick Sort took: %f seconds\n", quick_time);

    // Clean up
    free(array1);
    free(array2);
    
    return EXIT_SUCCESS;
}

void generate_random_array(int *array, size_t size) {
    srand(time(NULL));
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % MAX_VAL;
    }
}

void bubble_sort(int *array, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void quick_sort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}

double benchmark_sort(void (*sort_func)(int *, size_t), int *array, size_t size) {
    clock_t start = clock();
    sort_func(array, size);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

void print_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}