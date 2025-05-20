//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

void bucket_sort(int arr[], int n) {
    int i, j, k, count[MAX] = {0};
    int *bucket[MAX];

    for (i = 0; i < n; i++) {
        count[(arr[i] * 100) / MAX]++;
    }

    for (i = 0; i < MAX; i++) {
        if (count[i] > 0) {
            bucket[i] = (int *)malloc(count[i] * sizeof(int));
        }
    }

    for (i = 0; i < n; i++) {
        k = (arr[i] * 100) / MAX;
        bucket[k][count[k] - 1] = arr[i];
        count[k]--;
    }

    int index = 0;
    for (i = 0; i < MAX; i++) {
        if (bucket[i]!= NULL) {
            for (j = 0; j < count[i]; j++) {
                arr[index++] = bucket[i][j];
            }
            free(bucket[i]);
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

    clock_t start = clock();
    bucket_sort(arr, n);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted array using bucket sort:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %lf seconds\n", time_taken);

    return 0;
}