//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAGIC_NUMBER 42

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left + 1;
    for (int j = left + 1; j <= right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[left], arr[i - 1]);
    return i - 1;
}

int main() {
    int arr[10] = {4, 2, 7, 1, 3, 5, 8, 2, 6, 42};
    int n = sizeof(arr) / sizeof(arr[0]);

    // insertion sort base case
    if (n <= 1) {
        printf("The sorted array is: %d %d %d %d %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8]);
        return 0;
    }

    // partition the array
    int pivot = partition(arr, 0, n - 1);

    // recursive call
    int left = 0;
    int right = n - 1;
    partition(arr, left, right);

    // merge the two partitions
    int left_ptr = left + 1;
    int right_ptr = pivot + 1;
    int i = left_ptr;
    int j = right_ptr;
    int k = left;

    while (i <= right_ptr && j <= right) {
        if (arr[i] <= arr[j]) {
            swap(arr[k], arr[i]);
            k++;
            i++;
        } else {
            swap(arr[k], arr[j]);
            k++;
            j++;
        }
    }

    // handle the cases where the two partitions are empty or one of them is empty
    if (i > right_ptr) {
        swap(arr[k], arr[right_ptr]);
        k++;
    }
    if (j > right) {
        swap(arr[k], arr[right]);
        k++;
    }

    printf("The sorted array is: %d %d %d %d %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8]);
    return 0;
}