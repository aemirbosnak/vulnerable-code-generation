//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define N 10    // size of array
#define RANGE 10    // range of numbers (0 to RANGE-1)

void printArray(int arr[]) {
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[]) {
    int i, j, k;
    int cnt[RANGE] = {0};
    int *bucket[N];

    for (i = 0; i < N; i++) {   // counting the frequency of each element
        cnt[arr[i]]++;
    }

    for (i = 0; i < RANGE; i++) {   // allocating memory for each bucket
        bucket[i] = (int*)malloc(cnt[i] * sizeof(int));
        for (j = 0; j < cnt[i]; j++) {  // initializing the bucket with 0
            bucket[i][j] = 0;
        }
    }

    for (i = 0, j = 0; i < RANGE; i++) { // placing the elements in the bucket
        for (k = 0; k < cnt[i]; k++) {
            bucket[i][k] = arr[j];
            j++;
        }
    }

    for (i = 0; i < RANGE; i++) {   // sorting each bucket and overwriting the original array
        for (j = 0; j < cnt[i]; j++) {
            for (k = j+1; k < cnt[i]; k++) {    
                if (bucket[i][j] > bucket[i][k]) {
                    int temp = bucket[i][j];
                    bucket[i][j] = bucket[i][k];
                    bucket[i][k] = temp;
                }
            }
            arr[j] = bucket[i][j];
        }
    }

    for (i = 0; i < RANGE; i++) {   // deallocating the memory used by each bucket
        free(bucket[i]);
    }
}

int main() {
    int arr[] = {4, 2, 8, 9, 0, 1, 5, 3, 7, 6};

    printf("Original Array: ");
    printArray(arr);

    bucketSort(arr);

    printf("Sorted Array: ");
    printArray(arr);

    return 0;
}