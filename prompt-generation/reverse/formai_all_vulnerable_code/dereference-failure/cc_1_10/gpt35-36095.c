//FormAI DATASET v1.0 Category: Benchmarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 10000000

double getRandomDouble(double, double);
double* generateRandomArray(int);
void bubbleSort(double*, int);
void quickSort(double*, int, int);
void mergeSort(double*, int, int);
void merge(double*, int, int, int);
void printArray(double*, int);

int main() {

    clock_t start, end;
    double cpu_time_used;

    int arraySize = MAX_ARRAY_SIZE;
    double* array = generateRandomArray(arraySize);

    // Bubble Sort
    printf("Running Bubble Sort...\n");
    start = clock();
    bubbleSort(array, arraySize);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Time: %f seconds\n", cpu_time_used);

    // Quick Sort
    printf("\nRunning Quick Sort...\n");
    start = clock();
    quickSort(array, 0, arraySize-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort Time: %f seconds\n", cpu_time_used);

    // Merge Sort
    printf("\nRunning Merge Sort...\n");
    start = clock();
    mergeSort(array, 0, arraySize-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort Time: %f seconds\n", cpu_time_used);

    return 0;
}

/**
 * Generate a random double between two values
 */
double getRandomDouble(double min, double max) {
    return ((double)rand() / (double)(RAND_MAX)) * (max - min) + min;
}

/**
 * Generate a random array of given size
 */
double* generateRandomArray(int size) {
    double* array = malloc(size * sizeof(double));
    for (int i=0; i<size; i++) {
        array[i] = getRandomDouble(0, 1000000);
    }
    return array;
}

/**
 * Bubble Sort an array of given size
 */
void bubbleSort(double* array, int size) {
    for (int i=0; i<size-1; i++) {
        for (int j=0; j<size-i-1; j++) {
            if (array[j] > array[j+1]) {
                double temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

/**
 * Quick Sort an array of given size and specified range
 */
void quickSort(double* array, int low, int high) {
    if (low < high) {
        int i = low, j = high;
        double pivot = array[(low+high)/2];

        while (i <= j) {
            while (array[i] < pivot) {
                i++;
            }
            while (array[j] > pivot) {
                j--;
            }
            if (i <= j) {
                double temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
        }

        if (low < j) {
            quickSort(array, low, j);
        }
        if (i < high) {
            quickSort(array, i, high);
        }
    }
}

/**
 * Merge Sort an array of given size and specified range
 */
void mergeSort(double* array, int low, int high) {
    if (low < high) {
        int middle = (low+high)/2;

        mergeSort(array, low, middle);
        mergeSort(array, middle+1, high);

        merge(array, low, middle, high);
    }
}

/**
 * Merge two sorted arrays
 */
void merge(double* array, int low, int middle, int high) {
    int n1 = middle - low + 1;
    int n2 = high - middle;
    double L[n1], R[n2];

    for (int i=0; i<n1; i++) {
        L[i] = array[low+i];
    }
    for (int j=0; j<n2; j++) {
        R[j] = array[middle+j+1];
    }

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

/**
 * Print an array of given size
 */
void printArray(double* array, int size) {
    for (int i=0; i<size; i++) {
        printf("%f ", array[i]);
    }
    printf("\n");
}