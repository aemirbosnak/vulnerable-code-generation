//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int n) {
    int i, j, k, num;
    int buckets[MAX_SIZE];
    for (i = 0; i < MAX_SIZE; i++) {
        buckets[i] = 0;
    }
    for (i = 0; i < n; i++) {
        num = arr[i];
        if (num >= 0) {
            buckets[num]++;
        } else {
            buckets[MAX_SIZE + num]++;
        }
    }
    for (i = 0; i < MAX_SIZE; i++) {
        if (buckets[i] > 0) {
            for (j = 0; j < buckets[i]; j++) {
                if (i >= 0) {
                    arr[j] = i;
                } else {
                    arr[j] = MAX_SIZE + i;
                }
            }
        }
    }
}

int main() {
    int n, i, j;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start = clock();
    bucketSort(arr, n);
    clock_t end = clock();
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds\n", time_taken);
    return 0;
}