//Falcon-180B DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int generateRandomNumber(int min, int max);
int *createArray(int size);
void printArray(int *array, int size);
void sortArray(int *array, int size);
void searchArray(int *array, int size, int target);

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *array = createArray(size);
    printf("Unsorted array:\n");
    printArray(array, size);

    sortArray(array, size);
    printf("\nSorted array:\n");
    printArray(array, size);

    int target;
    printf("Enter a target number to search for: ");
    scanf("%d", &target);
    searchArray(array, size, target);

    free(array);
    return 0;
}

// Generates a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Creates an integer array of size'size'
int *createArray(int size) {
    int *array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = generateRandomNumber(1, 100);
    }
    return array;
}

// Prints an integer array of size'size'
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Sorts an integer array of size'size' in ascending order
void sortArray(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

// Searches for a target number in an integer array of size'size'
void searchArray(int *array, int size, int target) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Target number not found.\n");
    } else {
        printf("Target number found at index %d.\n", index);
    }
}