//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void generateRandomArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Random integers between 0 and 999
    }
}

void measureSortingTime(void (*sortFunc)(int *, int), int *arr, int n, const char *sortName) {
    int *arrCopy = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arrCopy[i] = arr[i];
    }
    
    clock_t startTime = clock();
    sortFunc(arrCopy, n);
    clock_t endTime = clock();
    
    double timeTaken = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    printf("%s took %f seconds.\n", sortName, timeTaken);
    
    free(arrCopy);
}

int main() {
    srand(time(NULL));
    
    int n = 1000; // Size of the array
    int *arr = malloc(n * sizeof(int));
    generateRandomArray(arr, n);
    
    printf("Benchmarking sorting algorithms on an array of size %d...\n", n);
    
    measureSortingTime(bubbleSort, arr, n, "Bubble Sort");
    measureSortingTime(insertionSort, arr, n, "Insertion Sort");
    measureSortingTime(quickSort, arr, n, "Quick Sort");
    
    free(arr);
    return 0;
}