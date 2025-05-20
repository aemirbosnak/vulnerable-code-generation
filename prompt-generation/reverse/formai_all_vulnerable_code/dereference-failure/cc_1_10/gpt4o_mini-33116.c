//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubbleSort(int array[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void selectionSort(int array[], int size) {
    int i, j, minIndex;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        swap(&array[minIndex], &array[i]);
    }
}

void insertionSort(int array[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void merge(int array[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

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

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void readArray(int array[], int* size) {
    printf("Enter number of elements in array: ");
    scanf("%d", size);
    printf("Enter elements: ");
    for (int i = 0; i < *size; i++) {
        scanf("%d", &array[i]);
    }
}

int main() {
    int array[MAX_SIZE];
    int size = 0;

    readArray(array, &size);
    
    printf("\nOriginal Array:\n");
    printArray(array, size);

    printf("\nArray sorted using Bubble Sort:\n");
    bubbleSort(array, size);
    printArray(array, size);

    readArray(array, &size);
    printf("\nArray sorted using Selection Sort:\n");
    selectionSort(array, size);
    printArray(array, size);

    readArray(array, &size);
    printf("\nArray sorted using Insertion Sort:\n");
    insertionSort(array, size);
    printArray(array, size);

    readArray(array, &size);
    printf("\nArray sorted using Merge Sort:\n");
    mergeSort(array, 0, size - 1);
    printArray(array, size);

    readArray(array, &size);
    printf("\nArray sorted using Quick Sort:\n");
    quickSort(array, 0, size - 1);
    printArray(array, size);

    return 0;
}