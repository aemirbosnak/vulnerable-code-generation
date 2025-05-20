//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swapping
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Visual Representation of Sorting
                printf("After swapping %d and %d:\n", arr[j], arr[j + 1]);
                printArray(arr, size);
                usleep(500000); // Sleep for half a second
            }
        }
    }
}

int main() {
    char input[256];
    int *array = NULL;
    int size = 0;

    printf("Welcome to the Genius Sorting Program!\n");
    printf("Please enter the numbers to be sorted (space-separated). Type 'END' to finish:\n");

    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "END", 3) == 0) {
            break;
        }

        char *token = strtok(input, " ");
        while (token != NULL) {
            array = realloc(array, sizeof(int) * (size + 1));
            if (array == NULL) {
                fprintf(stderr, "Memory allocation failed!\n");
                return 1;
            }
            array[size++] = atoi(token);
            token = strtok(NULL, " ");
        }
    }

    if (size == 0) {
        printf("No numbers provided. Exiting the program.\n");
        free(array);
        return 0;
    }

    printf("You have entered the following numbers:\n");
    printArray(array, size);

    printf("Starting bubble sort...\n");
    bubbleSort(array, size);

    printf("Sorted array:\n");
    printArray(array, size);

    free(array);
    return 0;
}