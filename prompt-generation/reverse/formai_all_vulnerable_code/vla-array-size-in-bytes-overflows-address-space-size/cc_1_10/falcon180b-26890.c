//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array into buckets
void partition(int arr[], int n, int max) {
    int i;
    for (i = 0; i < n; i++) {
        int bucket_index = arr[i] / max;
        int j = 0;
        while (j < i && arr[j] / max == bucket_index) {
            j++;
        }
        swap(&arr[i], &arr[j]);
    }
}

// Function to perform bucket sort recursively
void bucket_sort(int arr[], int n, int max) {
    if (n <= 1) {
        return;
    }
    int bucket_size = max / n;
    int bucket_count = 0;
    int i;
    for (i = 0; i < n; i++) {
        bucket_count++;
        while (arr[i] / bucket_size == bucket_count) {
            i++;
        }
        swap(&arr[i], &arr[bucket_count]);
    }
    for (i = 0; i < n; i++) {
        bucket_sort(arr, bucket_size, max);
    }
}

int main() {
    int n, i;
    srand(time(NULL));
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i] = rand_num(0, MAX_SIZE);
    }
    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucket_sort(arr, n, MAX_SIZE);
    printf("After sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}