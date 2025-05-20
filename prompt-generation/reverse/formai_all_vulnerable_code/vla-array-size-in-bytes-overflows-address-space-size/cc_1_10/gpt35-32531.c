//FormAI DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int key) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            return binarySearch(arr, left, mid - 1, key);
        }
        else {
            return binarySearch(arr, mid + 1, right, key);
        }
    }
    return -1;
}

// Driver function
int main() {
    int n, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &key);

    // Performing Linear Search
    int linearResult = linearSearch(arr, n, key);
    if (linearResult != -1) {
        printf("%d found at position %d using Linear Search\n", key, linearResult + 1);
    }
    else {
        printf("%d not found using Linear Search\n", key);
    }

    // Sorting the array
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Performing Binary Search
    int binaryResult = binarySearch(arr, 0, n-1, key);
    if (binaryResult != -1) {
        printf("%d found at position %d using Binary Search\n", key, binaryResult + 1);
    }
    else {
        printf("%d not found using Binary Search\n", key);
    }

    return 0;
}