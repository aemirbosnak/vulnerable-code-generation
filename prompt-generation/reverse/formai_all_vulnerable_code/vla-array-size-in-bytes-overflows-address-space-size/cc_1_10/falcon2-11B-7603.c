//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int maxIterations = 1000;
    srand(time(NULL));
    int randomIndex = rand() % n;
    int temp = arr[randomIndex];
    arr[randomIndex] = arr[n-1];
    arr[n-1] = temp;
    printf("Array before sorting: ");
    printArray(arr, n);
    clock_t start, end;
    start = clock();
    bubbleSort(arr, n);
    end = clock();
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Array after sorting: ");
    printArray(arr, n);
    printf("Time taken: %f seconds\n", timeTaken);
    return 0;
}