//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void bucketSort(int arr[], int n) {
    int bucket[MAX_SIZE];
    int i, j;

    for (i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    for (i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]!= 0) {
            for (j = 0; j < bucket[i]; j++) {
                arr[n - bucket[i] + j] = i;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        swap(&arr[i], &arr[rand() % n]);
    }

    printf("Sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}