//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: active
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap arr[minIndex] and arr[i]
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Welcome to the Sorting Adventure Program!\n");
    printf("Enter number of elements you want to sort: ");
    scanf("%d", &n);
    
    int* arr = (int*) malloc(n * sizeof(int));
    
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int choice;
    printf("\nSelect a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("\nYou chose Bubble Sort! Sorting...\n");
            bubbleSort(arr, n);
            printf("Sorted array using Bubble Sort: ");
            break;
        case 2:
            printf("\nYou chose Selection Sort! Sorting...\n");
            selectionSort(arr, n);
            printf("Sorted array using Selection Sort: ");
            break;
        case 3:
            printf("\nYou chose Insertion Sort! Sorting...\n");
            insertionSort(arr, n);
            printf("Sorted array using Insertion Sort: ");
            break;
        default:
            printf("Invalid choice! Please restart the program and try again.\n");
            free(arr);
            return 1;
    }
    
    printArray(arr, n);
    free(arr);
    
    printf("\nThank you for joining this Sorting Adventure!\n");
    return 0;
}