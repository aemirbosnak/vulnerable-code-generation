//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the array
#define MAX_SIZE 1000

// Define the data structure for the array
typedef struct {
    int data[MAX_SIZE];
    int size;
} Array;

// Function to initialize an empty array
Array* initArray() {
    Array* arr = (Array*) malloc(sizeof(Array));
    arr->size = 0;
    return arr;
}

// Function to insert an element into the array
void insertElement(Array* arr, int element) {
    if (arr->size == MAX_SIZE) {
        printf("Error: Array is full.\n");
        return;
    }
    arr->data[arr->size++] = element;
}

// Function to search for an element in the array
int searchElement(Array* arr, int element) {
    int i;
    for (i = 0; i < arr->size; i++) {
        if (arr->data[i] == element) {
            return i;
        }
    }
    return -1; // Element not found
}

// Function to print the array
void printArray(Array* arr) {
    int i;
    for (i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

// Function to generate a random array of integers
void generateRandomArray(Array* arr) {
    srand(time(NULL));
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        insertElement(arr, rand() % 1000);
    }
}

// Function to sort the array in ascending order
void sortArray(Array* arr) {
    int i, j;
    for (i = 0; i < arr->size - 1; i++) {
        for (j = i + 1; j < arr->size; j++) {
            if (arr->data[i] > arr->data[j]) {
                int temp = arr->data[i];
                arr->data[i] = arr->data[j];
                arr->data[j] = temp;
            }
        }
    }
}

// Function to perform binary search on the array
int binarySearch(Array* arr, int element) {
    int left = 0;
    int right = arr->size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr->data[mid] == element) {
            return mid;
        } else if (arr->data[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Element not found
}

int main() {
    Array* arr = initArray();
    generateRandomArray(arr);
    sortArray(arr);
    printf("Sorted array:\n");
    printArray(arr);
    int element = 500;
    int index = binarySearch(arr, element);
    if (index == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index %d.\n", index);
    }
    return 0;
}