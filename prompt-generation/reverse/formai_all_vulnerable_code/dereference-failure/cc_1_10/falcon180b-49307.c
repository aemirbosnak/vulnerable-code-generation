//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateArray(int *arr, int size);
void printArray(int *arr, int size);
double measureExecutionTime(int *arr, int size, int (*func)(int *, int));

int sumArray(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int size = 1000000; // Array size
    int *arr = (int *)malloc(size * sizeof(int)); // Allocate memory for array

    srand(time(NULL)); // Seed random number generator with current time
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Fill array with random numbers between 0 and 99
    }

    printf("Original array:\n");
    printArray(arr, size);

    double executionTime = measureExecutionTime(arr, size, sumArray);
    printf("Execution time: %.6f seconds\n", executionTime);

    free(arr); // Free allocated memory
    return 0;
}

void generateArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

double measureExecutionTime(int *arr, int size, int (*func)(int *, int)) {
    clock_t startTime, endTime;
    double cpuTimeUsed;

    startTime = clock();
    func(arr, size);
    endTime = clock();

    cpuTimeUsed = ((double) (endTime - startTime)) / CLOCKS_PER_SEC;
    return cpuTimeUsed;
}