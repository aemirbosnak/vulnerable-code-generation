//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int *input, int n) {
    int maxValue = input[0];
    for (int i = 1; i < n; i++) {
        if (input[i] > maxValue) {
            maxValue = input[i];
        }
    }

    int bucketCount = maxValue + 1;
    int **buckets = (int**)malloc(sizeof(int*) * bucketCount);
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = (int*)malloc(sizeof(int) * MAX_SIZE);
    }

    int *bucketSizes = (int*)calloc(bucketCount, sizeof(int));

    for (int i = 0; i < n; i++) {
        int bucketIndex = input[i];
        buckets[bucketIndex][bucketSizes[bucketIndex]] = input[i];
        bucketSizes[bucketIndex]++;
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            input[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

int main() {
    int input[] = {2, 5, 3, 1, 4, 6, 7, 8, 3, 2};
    int n = sizeof(input) / sizeof(input[0]);

    bucketSort(input, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");

    return 0;
}