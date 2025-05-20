//FormAI DATASET v1.0 Category: Benchmarking ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 1000000

// Function that generates an array of random integers
int* generateArray() {
    int* arr = malloc(sizeof(int) * LENGTH);
    srand(time(NULL));
    for (int i = 0; i < LENGTH; i++) {
        arr[i] = rand() % LENGTH;
    }
    return arr;
}

// Function to swap two elements in an array
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to implement bubble sort algorithm
void bubbleSort(int* arr) {
    for (int i = 0; i < LENGTH-1; i++) {
        for (int j = 0; j < LENGTH-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;
    int* arr = generateArray();

    start = clock();
    bubbleSort(arr);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for bubble sort algorithm on array of length %d: %f seconds", LENGTH, cpu_time_used);

    free(arr);
    
    return 0;
}