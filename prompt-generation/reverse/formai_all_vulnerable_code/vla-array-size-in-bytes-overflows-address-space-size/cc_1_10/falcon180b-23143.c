//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bucketSort(int arr[], int n) {
    int i, j;
    int min, max, range;
    int *bucket[MAX];

    for (i = 0; i < MAX; i++) {
        bucket[i] = (int*) malloc(n * sizeof(int));
    }

    min = arr[0];
    max = arr[0];

    for (i = 0; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }

    range = max - min + 1;

    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / range * MAX;
        bucket[j] = (int*) realloc(bucket[j], (j + 1) * sizeof(int));
        bucket[j][j] = arr[i];
    }

    i = 0;

    for (j = 0; j < MAX; j++) {
        while (bucket[j][i]!= 0) {
            arr[i] = bucket[j][i];
            i++;
        }
    }

    for (j = 0; j < MAX; j++) {
        free(bucket[j]);
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

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        swap(&arr[i], &arr[rand() % n]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}