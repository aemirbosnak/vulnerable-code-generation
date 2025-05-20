//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Custom sorting function using bubble sort
void sortArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// Custom function to check if an array is sorted in ascending order
int isSorted(int* a, int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Custom quickselect function to find the k-th smallest element
int quickselect(int* a, int n, int k) {
    if (n <= 1) {
        return a[0];
    }

    // Partition the array around a random element
    int pivot = a[rand() % n];
    int left_size = 0;
    int right_size = 0;
    int* left = malloc(sizeof(int) * n);
    int* right = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        if (a[i] < pivot) {
            left[left_size++] = a[i];
        } else if (a[i] > pivot) {
            right[right_size++] = a[i];
        }
    }

    free(a);

    if (left_size == k) {
        return pivot;
    } else if (left_size < k) {
        return quickselect(right, right_size, k - left_size - 1);
    } else {
        return quickselect(left, left_size, k);
    }
}

int main() {
    // Generate a random array of 1000 integers
    int n = 1000;
    int* a = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        a[i] = rand() % n;
    }

    // Sort the array using bubble sort
    sortArray(a, n);

    // Check if the array is sorted
    if (isSorted(a, n)) {
        printf("The array is sorted!\n");
    } else {
        printf("The array is not sorted!\n");
    }

    // Find the median of the array using quickselect
    int median = quickselect(a, n, n / 2);
    printf("The median of the array is: %d\n", median);

    free(a);
    return 0;
}