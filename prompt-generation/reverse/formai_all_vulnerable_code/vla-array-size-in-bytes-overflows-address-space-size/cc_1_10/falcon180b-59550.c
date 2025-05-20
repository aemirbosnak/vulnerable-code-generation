//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_RANGE 1000

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insert_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucket_sort(int arr[], int n) {
    int i, j, max_val = arr[0];
    int *bucket = (int *)malloc(MAX_SIZE * sizeof(int));
    for (i = 0; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    for (i = 0; i < MAX_RANGE; i++) {
        bucket[i] = 0;
    }
    for (i = 0; i < n; i++) {
        j = arr[i] / (MAX_RANGE / n);
        bucket[j]++;
    }
    for (i = 0; i < MAX_RANGE; i++) {
        for (j = 0; j < bucket[i]; j++) {
            arr[j * n + i] = i * (MAX_RANGE / n) + (j + 1) * (MAX_RANGE / n);
        }
    }
    for (i = 0; i < n; i++) {
        insert_sort(&arr[i * n], n);
    }
    free(bucket);
}

void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int i, n;
    srand(time(0));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Before sorting:\n");
    print_array(arr, n);
    bucket_sort(arr, n);
    printf("After sorting:\n");
    print_array(arr, n);
    return 0;
}