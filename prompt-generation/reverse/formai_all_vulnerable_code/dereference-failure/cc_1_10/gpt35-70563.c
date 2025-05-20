//FormAI DATASET v1.0 Category: Benchmarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

int *gen_random_array(int number_of_elements) {
    int *array = malloc(sizeof(int) * number_of_elements);
    srand(time(0));
    for (int i = 0; i < number_of_elements; i++) {
        array[i] = rand() % 100;
    }
    return array;
}

double bubble_sort(int *array, int size) {
    clock_t start_time = clock();

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    return (double)(clock() - start_time) / CLOCKS_PER_SEC;
}

double quick_sort(int *array, int left, int right) {
    clock_t start_time = clock();

    if (left < right) {
        int pivot = array[right];
        int i = left - 1;
        for (int j = left; j <= right - 1; j++) {
            if (array[j] < pivot) {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        int temp = array[i + 1];
        array[i + 1] = array[right];
        array[right] = temp;

        quick_sort(array, left, i);
        quick_sort(array, i + 2, right);
    }

    return (double)(clock() - start_time) / CLOCKS_PER_SEC;
}

int main() {
    int *array = gen_random_array(SIZE);
    double bubble_time = bubble_sort(array, SIZE);
    printf("Bubble Sort Time: %f\n", bubble_time);
    double quick_time = quick_sort(array, 0, SIZE - 1);
    printf("Quick Sort Time: %f\n", quick_time);
    free(array);
    return 0;
}