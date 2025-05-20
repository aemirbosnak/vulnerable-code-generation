//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int *elements;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* create_dynamic_array(int capacity) {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->capacity = capacity;
    array->size = 0;
    array->elements = (int *)malloc(capacity * sizeof(int));
    return array;
}

void resize_dynamic_array(DynamicArray *array) {
    int new_capacity = array->capacity * 2;
    array->elements = (int *)realloc(array->elements, new_capacity * sizeof(int));
    array->capacity = new_capacity;
}

void add_element(DynamicArray *array, int element) {
    if (array->size == array->capacity) {
        resize_dynamic_array(array);
    }
    array->elements[array->size++] = element;
}

void free_dynamic_array(DynamicArray *array) {
    free(array->elements);
    free(array);
}

void quicksort(int *array, int low, int high) {
    if (low < high) {
        int pivot = array[high];
        int i = low - 1;
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
        int pi = i + 1;

        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

void benchmark_sorting_algorithm() {
    clock_t start, end;
    double cpu_time_used;
    
    DynamicArray *data = create_dynamic_array(MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++) {
        add_element(data, rand() % 10000);
    }

    start = clock();
    quicksort(data->elements, 0, data->size - 1);
    end = clock();
    
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Sorting completed in %f seconds.\n", cpu_time_used);
    
    free_dynamic_array(data);
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    
    printf("Performance-Critical Dynamic Array and Sorting Example:\n");
    benchmark_sorting_algorithm();
    
    return 0;
}