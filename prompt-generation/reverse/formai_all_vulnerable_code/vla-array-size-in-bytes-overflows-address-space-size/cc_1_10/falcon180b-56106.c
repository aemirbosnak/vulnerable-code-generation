//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
    int i, j, k, max, min;
    int bucket[100];

    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            printf("Invalid input!\n");
            exit(0);
        }
    }

    max = arr[0];
    min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    k = (max - min) / n + 1;

    for (i = 0; i < n; i++) {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / k;
        bucket[j]++;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < bucket[i]; j++) {
            printf("%d ", arr[i]);
        }
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    return 0;
}