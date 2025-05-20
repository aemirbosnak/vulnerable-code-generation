//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void bucketSort(int arr[], int n) {
    int i, j;
    int max = arr[0];
    int min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min + 1;
    int *bucket = (int *) malloc(range * sizeof(int));
    for (i = 0; i < range; i++) {
        bucket[i] = 0;
    }
    for (i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }
    int k = 0;
    for (i = 0; i < range; i++) {
        for (j = 0; j < bucket[i]; j++) {
            arr[k++] = i + min;
        }
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int i, n;
    srand(time(NULL));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Before sorting:\n");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("After sorting:\n");
    printArray(arr, n);
    return 0;
}