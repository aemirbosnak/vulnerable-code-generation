//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

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
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    int range = max - min + 1;
    int* bucket = (int*) malloc(range * sizeof(int));

    for (int i = 0; i < range; i++)
        bucket[i] = 0;

    for (int i = 0; i < n; i++)
        bucket[arr[i] - min]++;

    for (int i = 1; i < range; i++)
        bucket[i] += bucket[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        arr[bucket[arr[i] - min] - 1] = arr[i];
        bucket[arr[i] - min]--;
    }

    free(bucket);
}

int main() {
    int arr[MAX];
    int n;

    srand(time(0));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted array: \n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}