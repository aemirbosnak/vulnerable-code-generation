//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main(void) {
    int arr[MAX_SIZE];
    int n, i, max, min;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
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

    int bucket_size = (max - min) / n;

    int *buckets[n];

    for (i = 0; i < n; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * (max - min + 1));
        for (int j = 0; j <= max - min; j++) {
            buckets[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++) {
        buckets[arr[i] - min][arr[i]]++;
    }

    for (i = 0; i < n; i++) {
        for (int j = 0; j <= max - min; j++) {
            if (buckets[i][j] > 0) {
                arr[i * bucket_size + j] = i * bucket_size + j;
                buckets[i][j]--;
            }
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}