//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define RANGE 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min + 1;
    int *bucket = (int *)malloc(range * sizeof(int));
    for (int i = 0; i < range; i++) {
        bucket[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (bucket[i] > 0) {
            arr[index++] = i + min;
            bucket[i]--;
        }
    }
    free(bucket);
}

int main() {
    int arr[MAX_SIZE];
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Unsorted array:\n");
    print_array(arr, n);
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    print_array(arr, n);
    return 0;
}