//FormAI DATASET v1.0 Category: Benchmarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Quick Sort implementation
void quickSort(int array[], int left, int right) {
    int i = left, j = right;
    int temp;
    int pivot = array[(left + right)/2];
    
    while (i <= j) {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    
    if (left < j) {
        quickSort(array, left, j);
    }
    if (i < right) {
        quickSort(array, i, right);
    }
}

// Merge Sort implementation
void merge(int array[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    
    // Create temporary arrays
    int L[n1], R[n2];
    
    // Copy data to temporary arrays
    for (i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = array[middle + 1 + j];
    }
    
    // Merge the temporary arrays back into the main array
    i = 0;
    j = 0;
    k = left;
    
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
    
    // Copy the remaining elements of L[] or R[], if any
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

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        
        // Sort first half
        mergeSort(array, left, middle);
        // Sort second half
        mergeSort(array, middle + 1, right);
        
        // Merge both halves
        merge(array, left, middle, right);
    }
}

int main() {
    srand(time(NULL));
    
    int size = 100000;
    
    // Allocate memory for the array
    int *array = (int*) malloc(size * sizeof(int));
    
    // Generate random data for the array
    for (int i = 0; i < size; i++) {
        array[i] = rand() % size;
    }
    
    // Benchmark the Quick Sort algorithm
    clock_t quickStart = clock();
    quickSort(array, 0, size - 1);
    clock_t quickEnd = clock();
    double quickTime = ((double) (quickEnd - quickStart)) / CLOCKS_PER_SEC;
    
    // Re-generate random data for the array
    for (int i = 0; i < size; i++) {
        array[i] = rand() % size;
    }
    
    // Benchmark the Merge Sort algorithm
    clock_t mergeStart = clock();
    mergeSort(array, 0, size - 1);
    clock_t mergeEnd = clock();
    double mergeTime = ((double) (mergeEnd - mergeStart)) / CLOCKS_PER_SEC;
    
    // Print the benchmark results
    printf("Quick Sort took %f seconds.\n", quickTime);
    printf("Merge Sort took %f seconds.", mergeTime);
    
    // Free the memory allocated for the array
    free(array);
    
    return 0;
}