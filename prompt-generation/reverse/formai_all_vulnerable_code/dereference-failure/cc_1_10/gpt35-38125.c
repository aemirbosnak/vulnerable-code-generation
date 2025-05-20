//FormAI DATASET v1.0 Category: Searching algorithm ; Style: genious
#include<stdio.h>
#include<stdlib.h>

/* Function to perform linear search in a given array */
int linearSearch(int array[], int size, int searchKey) {
    for (int i = 0; i < size; i++) {
        /* Check if the current element is equal to the search key */
        if (array[i] == searchKey) {
            return i;
        }
    }
    /* Return -1 if the search key is not found in the array */
    return -1;
}

/* Function to perform binary search in a given array */
int binarySearch(int array[], int size, int searchKey) {
    int leftIndex = 0;
    int rightIndex = size - 1;
    while (leftIndex <= rightIndex) {
        int middleIndex = (leftIndex + rightIndex) / 2;
        /* Check if the middle element is equal to the search key */
        if (array[middleIndex] == searchKey) {
            return middleIndex;
        }
        /* If the middle element is less than the search key */
        else if (array[middleIndex] < searchKey) {
            leftIndex = middleIndex + 1;
        }
        /* If the middle element is greater than the search key */
        else {
            rightIndex = middleIndex - 1;
        }
    }
    /* Return -1 if the search key is not found in the array */
    return -1;
}

int main() {
    int size, searchKey, searchMethod, searchIndex;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    /* Allocate memory for the array dynamically */
    int *array = (int*) malloc(size * sizeof(int));
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter the search key: ");
    scanf("%d", &searchKey);
    printf("Enter the search method (1 for linear search, 2 for binary search): ");
    scanf("%d", &searchMethod);
    /* Perform the selected search operation on the array */
    if (searchMethod == 1) {
        searchIndex = linearSearch(array, size, searchKey);
    }
    else if (searchMethod == 2) {
        searchIndex = binarySearch(array, size, searchKey);
    }
    else {
        printf("Invalid search method selected.\n");
        free(array);
        return 0;
    }
    /* Display the search result */
    if (searchIndex == -1) {
        printf("The search key was not found in the array.\n");
    }
    else {
        printf("The search key was found at index %d in the array.\n", searchIndex);
    }
    /* Free the memory allocated for the array */
    free(array);
    return 0;
}