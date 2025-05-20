//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucket_sort(int arr[], int n) {
    int i, j, max, min, range, temp;
    int *bucket[MAX_SIZE];

    max = arr[0];
    min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    range = max - min + 1;

    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        temp = (arr[i] - min) * MAX_SIZE / range;
        bucket[temp] = realloc(bucket[temp], (j + 1) * sizeof(int));
        bucket[temp][j] = arr[i];
        j++;
    }

    j = 0;

    for (i = 0; i < MAX_SIZE; i++) {
        for (int k = 0; k < j; k++) {
            arr[k] = bucket[i][k];
        }
        j += j;
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

    bucket_sort(arr, n);

    printf("Sorted array:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}