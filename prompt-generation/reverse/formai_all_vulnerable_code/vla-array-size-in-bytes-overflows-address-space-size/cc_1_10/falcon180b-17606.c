//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 1000

// Function to find the maximum value in an array
int max(int arr[], int n) {
    int max_value = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    return max_value;
}

// Function to perform bucket sort
void bucket_sort(int arr[], int n) {
    int bucket_size = max(arr, n) / n;

    int *buckets[n];

    for (int i = 0; i < n; i++) {
        buckets[i] = (int *)malloc(bucket_size * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] <= (j * bucket_size) && arr[i] > ((j - 1) * bucket_size)) {
                int index = arr[i] - j * bucket_size;
                buckets[j][index] = arr[i];
            }
        }
    }

    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket_size; j++) {
            if (buckets[i][j]!= 0) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

// Function to print an array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    print_array(arr, n);

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}