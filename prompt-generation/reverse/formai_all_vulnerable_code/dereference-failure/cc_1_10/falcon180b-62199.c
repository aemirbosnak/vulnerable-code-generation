//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucketSort(int arr[], int n) {
    int i, j, k, nbuckets, maxval, minval, range, temp[100];
    float factor;

    nbuckets = 10; //Number of buckets
    maxval = arr[0];
    minval = arr[0];

    for(i = 1; i < n; i++) {
        if(arr[i] > maxval)
            maxval = arr[i];
        if(arr[i] < minval)
            minval = arr[i];
    }

    range = maxval - minval + 1;
    factor = n / range;

    for(i = 0; i < nbuckets; i++) {
        temp[i] = 0;
    }

    for(i = 0; i < n; i++) {
        k = (arr[i] - minval) * factor;
        temp[k]++;
    }

    for(i = 1; i < nbuckets; i++) {
        temp[i] += temp[i - 1];
    }

    for(i = n - 1; i >= 0; i--) {
        k = (arr[i] - minval) * factor;
        temp[k]--;
        arr[temp[k]] = arr[i];
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}