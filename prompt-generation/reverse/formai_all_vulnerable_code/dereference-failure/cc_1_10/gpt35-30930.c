//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Linus Torvalds
/* Linus Torvalds Style Quicksort implementation */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int n, arr[MAXSIZE];
    printf("Enter the size of the input array (<= 100000): ");
    scanf("%d", &n);
    
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAXSIZE;
    }
    
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    quicksort(arr, 0, n - 1);
    
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}