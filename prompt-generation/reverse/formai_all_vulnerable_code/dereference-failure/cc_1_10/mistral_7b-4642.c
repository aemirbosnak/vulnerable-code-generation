//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 10000
#define KEY_SIZE 32

typedef struct {
    int size;
    int capacity;
    int* arr;
} Array;

void createArray(Array* arr) {
    arr->capacity = 2 * MAX_SIZE;
    arr->size = 0;
    arr->arr = (int*)calloc(arr->capacity, sizeof(int));
}

void addElement(Array* arr, int key) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->arr = (int*)realloc(arr->arr, arr->capacity * sizeof(int));
    }
    arr->arr[arr->size++] = key;
}

int binarySearchWithWrapAround(const Array* arr, int key) {
    int left = 0;
    int right = arr->size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr->arr[mid] == key) {
            return mid;
        }

        if (arr->arr[mid] < key) {
            left = mid + 1;
        } else {
            if (mid > 0) {
                right = mid - 1;
            } else {
                int size = arr->size;
                int start = 0;

                while (left < size) {
                    mid = left + (size - left) / 2;

                    if (arr->arr[mid] == key) {
                        return mid + arr->size - size;
                    }

                    if (arr->arr[mid] < key) {
                        left = mid + 1;
                    } else {
                        size -= (mid + 1 - start);
                        start = mid + 1;
                    }
                }

                return -1;
            }
        }
    }

    return -1;
}

int main() {
    Array arr;
    createArray(&arr);

    addElement(&arr, 10);
    addElement(&arr, 5);
    addElement(&arr, 20);
    addElement(&arr, 15);
    addElement(&arr, 3);
    addElement(&arr, 25);
    addElement(&arr, 8);
    addElement(&arr, 2);
    addElement(&arr, 22);

    printf("Searching for 15: %d\n", binarySearchWithWrapAround(&arr, 15));
    printf("Searching for 33: %d\n", binarySearchWithWrapAround(&arr, 33));

    return 0;
}