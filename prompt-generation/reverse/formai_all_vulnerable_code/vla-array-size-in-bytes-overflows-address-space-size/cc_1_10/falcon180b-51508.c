//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n) {
    int i, j, max, min, temp;
    int bucket[MAX_SIZE];
    int count[MAX_SIZE] = { 0 };

    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            min = -arr[i];
        } else {
            min = arr[i];
        }
        max = min * 2;
        count[(min / 10)]++;
    }

    for (i = 0; i < MAX_SIZE; i++) {
        if (count[i] > 0) {
            bucket[i] = (i * 10);
        }
    }

    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            min = -arr[i];
        } else {
            min = arr[i];
        }
        max = min * 2;
        j = (min / 10);
        temp = arr[i];
        arr[i] = bucket[j];
        bucket[j] = temp;
    }

    for (i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            j = (arr[i] / 10);
            arr[i] = bucket[j];
            bucket[j] = -1;
        }
    }
}

int main() {
    int i, n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}