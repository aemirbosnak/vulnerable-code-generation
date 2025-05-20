//FormAI DATASET v1.0 Category: Benchmarking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// In this artsy example program, we will create a benchmarking tool using C

int main() {
    int size = 1000000;

    // Initialize array with random values
    int *arr = (int*) malloc(sizeof(int) * size);
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size;
    }

    clock_t start, end;

    // Measuring the time taken to sort the array using bubble sort
    start = clock();
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();

    printf("Bubble sort done in %f seconds.\n", (double)(end-start)/CLOCKS_PER_SEC);

    // Measuring the time taken to sort the array using selection sort
    start = clock();
    for (int i = 0; i < size-1; i++) {
        int min_index = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
    end = clock();

    printf("Selection sort done in %f seconds.\n", (double)(end-start)/CLOCKS_PER_SEC);

    free(arr);
    return 0;
}