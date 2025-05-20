//Falcon2-11B DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n, i, j, k;
    int arr[100];
    int min_sum = 1000000000;
    int* indices;
    int* sums;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    indices = (int*)malloc(n * sizeof(int));
    sums = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        indices[i] = i;
        sums[i] = 0;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[indices[i]] + arr[indices[j]] < min_sum) {
                k = indices[i];
                indices[i] = indices[j];
                indices[j] = k;
                sums[i] = sums[j];
                sums[j] = arr[indices[i]] + arr[indices[j]];
            }
        }
    }

    printf("Minimum sum is %d\n", sums[0]);

    free(indices);
    free(sums);

    return 0;
}