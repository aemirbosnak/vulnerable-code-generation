//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void bucket_sort(int arr[], int n) {
    int i, j, max = arr[0], min = arr[0], range, bucket_size = (MAX_SIZE - 1) / n;
    int *buckets[MAX_SIZE];
    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    range = max - min + 1;
    for (i = 0; i < n; i++) {
        int index = (arr[i] - min) * n / range;
        if (index == n) {
            index--;
        }
        if (index < 0) {
            index = 0;
        }
        if (index >= MAX_SIZE) {
            index = MAX_SIZE - 1;
        }
        if (buckets[index] == NULL) {
            buckets[index] = (int *)malloc(bucket_size * sizeof(int));
        }
        int *bucket = buckets[index];
        int k = 0;
        while (k < bucket_size && bucket[k]!= -1) {
            k++;
        }
        bucket[k] = arr[i];
    }
    int index = 0;
    for (i = 0; i < n; i++) {
        if (arr[i]!= -1) {
            arr[index++] = arr[i];
        }
    }
    for (i = 0; i < n; i++) {
        arr[i] = -1;
    }
}

void generate_random_array(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    generate_random_array(arr, n);
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}