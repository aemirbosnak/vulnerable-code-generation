//FormAI DATASET v1.0 Category: Benchmarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the size of the array to be sorted
#define ARRAY_SIZE 100000

// function to generate a random array of integers
int* generate_random_array(int size) {
    // allocate memory for the array
    int* array = (int*)malloc(size * sizeof(int));

    // seed the random number generator
    srand(time(NULL));

    // fill the array with random numbers between 0 and 999
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;
    }

    // return the array
    return array;
}

// function to print the contents of an array
void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to sort an array using the bubble sort algorithm
void bubble_sort(int* array, int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

// function to measure the time taken by a function
double measure_time(void (*function)(int*, int), int* array, int size) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    function(array, size);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    return cpu_time_used;
}

// main function to demonstrate the benchmarking of bubble sort
int main() {
    // generate a random array of integers
    int* array = generate_random_array(ARRAY_SIZE);

    // print the unsorted array
    printf("Array before sorting:\n");
    print_array(array, ARRAY_SIZE);

    // measure the time taken by bubble sort to sort the array
    double time_taken = measure_time(bubble_sort, array, ARRAY_SIZE);

    // print the sorted array
    printf("Array after sorting:\n");
    print_array(array, ARRAY_SIZE);

    // print the time taken by bubble sort to sort the array
    printf("Time taken by bubble sort: %f seconds\n", time_taken);

    // free the memory allocated for the array
    free(array);

    return 0;
}