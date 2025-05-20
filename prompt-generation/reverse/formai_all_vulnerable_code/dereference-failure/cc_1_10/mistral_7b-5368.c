//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct {
    int key;
    char name[20];
} Element;

void swap(Element* a, Element* b) {
    Element temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

bool binarySearch(Element arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].key == key)
            return true;

        if (arr[mid].key < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

void selectionSort(Element arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].key < arr[min_idx].key)
                min_idx = j;
        }

        swap(&arr[i], &arr[min_idx]);
    }
}

void printArray(Element arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("{%d, %s} ", arr[i].key, arr[i].name);
    printf("\n");
}

void generateRandomArray(Element arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i].key = rand() % 100 + 1;
        strcpy(arr[i].name, (char*) malloc(sizeof(char) * (rand() % 10 + 2) + 1));
        for (int j = 0; j <= rand() % 10 + 2; j++)
            arr[i].name[j] = 'A' + rand() % 26;
    }
}

int main() {
    srand(time(NULL));
    int n, key;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    Element* arr = (Element*) malloc(n * sizeof(Element));

    generateRandomArray(arr, n);
    printArray(arr, n);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    if (binarySearch(arr, 0, n - 1, key))
        printf("Element found!\n");
    else
        printf("Element not found.\n");

    selectionSort(arr, n);
    printArray(arr, n);

    free(arr);
    return 0;
}