//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int n, int low, int high) {
    int pivot = arr[low];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[low]);
    return i + 1;
}

// Function to perform bucket sort
void bucket_sort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int range = max / n;
    int* buckets = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / range;
        buckets[bucket_index]++;
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = i * range;
        }
    }

    free(buckets);
}

// Function to generate random array
void generate_array(int arr[], int n) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
}

// Main function
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    generate_array(arr, n);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}