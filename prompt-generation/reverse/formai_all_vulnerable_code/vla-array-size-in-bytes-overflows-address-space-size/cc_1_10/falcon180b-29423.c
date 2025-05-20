//Falcon-180B DATASET v1.0 Category: Sorting ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    Element pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot.data) {
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

int compare(const void* a, const void* b) {
    Element* elemA = (Element*)a;
    Element* elemB = (Element*)b;

    return elemA->data - elemB->data;
}

void merge(Element arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i].data <= arr[j].data) {
            arr[k] = arr[i];
            i++;
        } else {
            arr[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        arr[k] = arr[i];
        i++;
        k++;
    }
}

void mergeSort(Element arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    srand(time(NULL));

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    Element arr[n];

    for (int i = 0; i < n; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        if (arr[i].data == arr[0].data) {
            printf("%d ", arr[i].index);
        }
    }

    return 0;
}