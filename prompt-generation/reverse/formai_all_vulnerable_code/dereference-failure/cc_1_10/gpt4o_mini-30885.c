//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void initializeArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        array[i] = rand() % 100; // Random values between 0 and 99
}

void bubbleSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap array[j] and array[j + 1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex])
                minIndex = j;
        }
        // Swap array[i] and array[minIndex]
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

void merge(int *array, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

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

    free(L);
    free(R);
}

void mergeSort(int *array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

double benchmarkSorting(void (*sortFunc)(int *, int), int *array, int size) {
    clock_t start, end;
    start = clock();
    
    sortFunc(array, size);
    
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int *array1 = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int *array2 = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int *array3 = (int *)malloc(ARRAY_SIZE * sizeof(int));

    initializeArray(array1, ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++)
        array2[i] = array1[i];
    for (int i = 0; i < ARRAY_SIZE; i++)
        array3[i] = array1[i];

    double timeBubble = benchmarkSorting(bubbleSort, array1, ARRAY_SIZE);
    printf("Bubble Sort time: %f seconds\n", timeBubble);

    double timeSelection = benchmarkSorting(selectionSort, array2, ARRAY_SIZE);
    printf("Selection Sort time: %f seconds\n", timeSelection);

    double timeMerge = benchmarkSorting(mergeSort, array3, ARRAY_SIZE);
    printf("Merge Sort time: %f seconds\n", timeMerge);

    free(array1);
    free(array2);
    free(array3);
    
    return 0;
}