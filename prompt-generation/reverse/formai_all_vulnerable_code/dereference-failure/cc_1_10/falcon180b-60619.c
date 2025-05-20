//Falcon-180B DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_VAL 100

typedef struct {
    int data;
    int index;
} data_t;

void swap(data_t *a, data_t *b) {
    data_t temp = *a;
    *a = *b;
    *b = temp;
}

int partition(data_t arr[], int low, int high) {
    int pivot = arr[high].data;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(data_t arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    data_t arr[MAX_SIZE];
    int n, i;
    srand(time(NULL));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        arr[i].data = rand() % MAX_VAL;
        arr[i].index = i;
    }
    quicksort(arr, 0, n - 1);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
    return 0;
}