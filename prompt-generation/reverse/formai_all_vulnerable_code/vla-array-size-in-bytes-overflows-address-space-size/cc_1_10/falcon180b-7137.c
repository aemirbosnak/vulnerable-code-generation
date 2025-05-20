//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the position of an element in a sorted array
int find_position(int arr[], int n, int element) {
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == element) {
            return mid;
        } else if (arr[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Function to perform bucket sort
void bucket_sort(int arr[], int n) {
    int i, j, k;
    int* bucket[MAX_SIZE];
    for (i = 0; i < n; i++) {
        int position = find_position(arr, n, arr[i]);
        if (position == -1) {
            printf("Element %d not found\n", arr[i]);
            exit(0);
        }
        bucket[position] = &arr[i];
    }
    for (i = 0; i < n; i++) {
        if (bucket[i]!= NULL) {
            arr[i] = *bucket[i];
        }
    }
}

// Function to print an array
void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    print_array(arr, n);
    return 0;
}