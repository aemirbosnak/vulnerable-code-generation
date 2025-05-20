//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Element;

void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Element arr[], int low, int high) {
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

void quickSort(Element arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(Element arr[], int target, int size) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].data == target) {
            return mid;
        }

        if (arr[mid].data < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n, target;
    scanf("%d", &n);

    Element arr[MAX_SIZE];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    quickSort(arr, 0, n - 1);

    scanf("%d", &target);

    int result = binarySearch(arr, target, n);

    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}