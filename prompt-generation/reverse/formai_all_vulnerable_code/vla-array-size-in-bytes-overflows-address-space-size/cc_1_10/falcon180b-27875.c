//Falcon-180B DATASET v1.0 Category: Recursive ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function to print an array in reverse order
void printArrayReverse(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Recursive function to generate a permutation of an array
void generatePermutation(int arr[], int size, int index) {
    // Base case: all elements have been permuted
    if (index == size) {
        printArrayReverse(arr, size);
    }
    else {
        // Permute the array by swapping the current element with all possible elements to its right
        for (int i = index; i < size; i++) {
            // Swap arr[index] with arr[i]
            int temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;

            // Recursively generate the permutation for the next element
            generatePermutation(arr, size, index + 1);

            // Backtrack: swap arr[index] with arr[i] again
            temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Generate all permutations of the array
    printf("All permutations of the array:\n");
    generatePermutation(arr, size, 0);

    return 0;
}