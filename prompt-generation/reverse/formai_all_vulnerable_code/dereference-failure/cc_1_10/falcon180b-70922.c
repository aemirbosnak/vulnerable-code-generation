//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 1000

// Function to generate random integers between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to perform bucket sort
void bucket_sort(int arr[], int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    int bucket_size = max_val / n;
    int* buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = (int*)malloc(bucket_size * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket_size; j++) {
            buckets[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        int bucket_idx = arr[i] / bucket_size;
        buckets[bucket_idx][arr[i] % bucket_size]++;
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket_size; j++) {
            if (buckets[i][j] > 0) {
                for (int k = 0; k < buckets[i][j]; k++) {
                    arr[index++] = i * bucket_size + j;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
}

// Function to print the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int n = rand_int(1, MAX_SIZE);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand_int(1, 1000);
    }
    printf("Before sorting:\n");
    print_array(arr, n);
    bucket_sort(arr, n);
    printf("After sorting:\n");
    print_array(arr, n);
    free(arr);
    return 0;
}