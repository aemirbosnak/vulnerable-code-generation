//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void bucketSort(float arr[], int n) {
    int i, j;
    float minVal = arr[0], maxVal = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        } else if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    int bucketNum = (int) ceil((maxVal - minVal + 1) / 10);
    float bucket[bucketNum][10];

    int bucketCnt[bucketNum];
    for (i = 0; i < bucketNum; i++) {
        bucketCnt[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int bucketIndex = (int) floor((arr[i] - minVal) / 10);
        bucket[bucketIndex][bucketCnt[bucketIndex]] = arr[i];
        bucketCnt[bucketIndex]++;
    }

    int index = 0;
    for (i = 0; i < bucketNum; i++) {
        for (j = 0; j < bucketCnt[i]; j++) {
            arr[index] = bucket[i][j];
            index++;
        }
    }
}

int main() {
    int i,n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d",&n);

    float arr[n];
    printf("Enter the array elements:\n");

    for(i = 0; i < n; i++){
        scanf("%f",&arr[i]);
    }

    printf("Before Sorting:\n");

    for(i = 0; i < n; i++){
        printf("%f ",arr[i]);
    }

    bucketSort(arr, n);

    printf("\nAfter Sorting:\n");

    for(i = 0; i < n; i++){
        printf("%f ",arr[i]);
    }

    return 0;
}