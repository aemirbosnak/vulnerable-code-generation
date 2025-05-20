//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *array;
    int size;
} DynamicArray;

DynamicArray* create_dynamic_array(int initial_size) {
    DynamicArray *d_array = (DynamicArray *)malloc(sizeof(DynamicArray));
    d_array->array = (int *)malloc(initial_size * sizeof(int));
    d_array->size = initial_size;
    return d_array;
}

void resize_dynamic_array(DynamicArray *d_array, int new_size) {
    d_array->array = (int *)realloc(d_array->array, new_size * sizeof(int));
    d_array->size = new_size;
}

void free_dynamic_array(DynamicArray *d_array) {
    free(d_array->array);
    free(d_array);
}

void populate_array(DynamicArray *d_array) {
    for (int i = 0; i < d_array->size; i++) {
        d_array->array[i] = rand() % 100; // Random values between 0 and 99
    }
}

void print_array(const DynamicArray *d_array) {
    for (int i = 0; i < d_array->size; i++) {
        printf("%d ", d_array->array[i]);
    }
    printf("\n");
}

int sum_array(const DynamicArray *d_array) {
    int sum = 0;
    for (int i = 0; i < d_array->size; i++) {
        sum += d_array->array[i];
    }
    return sum;
}

float average_array(const DynamicArray *d_array) {
    if (d_array->size == 0) return 0.0f;
    return (float)sum_array(d_array) / d_array->size;
}

int find_max(const DynamicArray *d_array) {
    int max = d_array->array[0];
    for (int i = 1; i < d_array->size; i++) {
        if (d_array->array[i] > max) {
            max = d_array->array[i];
        }
    }
    return max;
}

int find_min(const DynamicArray *d_array) {
    int min = d_array->array[0];
    for (int i = 1; i < d_array->size; i++) {
        if (d_array->array[i] < min) {
            min = d_array->array[i];
        }
    }
    return min;
}

void sort_array(DynamicArray *d_array) {
    for (int i = 0; i < d_array->size - 1; i++) {
        for (int j = 0; j < d_array->size - i - 1; j++) {
            if (d_array->array[j] > d_array->array[j + 1]) {
                int temp = d_array->array[j];
                d_array->array[j] = d_array->array[j + 1];
                d_array->array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int initial_size = 10; // Start with size 10
    DynamicArray *d_array = create_dynamic_array(initial_size);
    
    printf("Populating the dynamic array...\n");
    populate_array(d_array);
    
    printf("Initial array: ");
    print_array(d_array);
    
    printf("Sum of array: %d\n", sum_array(d_array));
    printf("Average of array: %.2f\n", average_array(d_array));
    printf("Max value in array: %d\n", find_max(d_array));
    printf("Min value in array: %d\n", find_min(d_array));
    
    printf("Sorting the array...\n");
    sort_array(d_array);
    printf("Sorted array: ");
    print_array(d_array);
    
    // Resize the array
    printf("Resizing the array to size 15...\n");
    resize_dynamic_array(d_array, 15);
    populate_array(d_array);
    
    printf("Resized array: ");
    print_array(d_array);
    
    printf("Final Sum of resized array: %d\n", sum_array(d_array));
    
    free_dynamic_array(d_array);
    return 0;
}