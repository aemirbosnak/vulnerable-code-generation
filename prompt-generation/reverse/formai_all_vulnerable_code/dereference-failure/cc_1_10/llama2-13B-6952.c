//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array of integers
void sort(int arr[], int low, int high) {
    int i, j, temp;

    // Base case: if the length of the array is 1 or less, return
    if (low >= high) return;

    // Partition the array into two parts: sorted and unsorted
    for (i = low + 1, j = high; i < j;) {
        // Find the first unsorted element
        while (arr[i] <= arr[j]) i++;

        // Swap the first unsorted element with the first element of the sorted part
        swap(arr[i], arr[low]);

        // Move the sorted part one position forward
        low++;

        // Repeat the partitioning process until the entire array is sorted
        for (; i < j;) {
            while (arr[i] <= arr[j]) i++;
            swap(arr[i], arr[low]);
            low++;
        }
    }
}

int main() {
    int arr[5] = { 8, 3, 6, 1, 4 };
    int low = 0, high = 4;

    // Sort the array
    sort(arr, low, high);

    // Print the sorted array
    printf("The sorted array is: \n");
    for (int i = low; i <= high; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}