//FormAI DATASET v1.0 Category: Sorting ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j, temp, min_index;
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main() {
    int n, i, choice;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(0));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    printf("\nUnsorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nChoose the sorting algorithm:\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            printf("\nSorted Array (Bubble Sort): ");
            break;
        case 2:
            selectionSort(arr, n);
            printf("\nSorted Array (Selection Sort): ");
            break;
        case 3:
            insertionSort(arr, n);
            printf("\nSorted Array (Insertion Sort): ");
            break;
        default:
            printf("\nInvalid Choice!\n");
            return 0;
    }

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}