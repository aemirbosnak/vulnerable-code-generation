//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int size) {
    // Create buckets
    int i, j, k;
    int numBuckets = 10;
    int count = 0;
    float minValue = arr[0];
    float maxValue = arr[0];
    float range, bucketSize;
    int* bucketCounts = NULL;
    float** buckets = NULL;

    // Get the min and max values in the array
    for (i = 1; i < size; i++) {        
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }

    // Calculate the range and bucket size
    range = maxValue - minValue;
    bucketSize = range / numBuckets;

    // Allocate space for the buckets and bucket counts
    bucketCounts = (int*)malloc(numBuckets * sizeof(int));
    buckets = (float**)malloc(numBuckets * sizeof(float*));

    for (i = 0; i < numBuckets; i++) {
        buckets[i] = (float*)malloc(size * sizeof(float));
        bucketCounts[i] = 0;
    }

    // Distribute the elements into the buckets
    for (i = 0; i < size; i++) {
        j = (int)((arr[i] - minValue) / bucketSize);
        if (j >= numBuckets) {
            j = numBuckets - 1;
        }
        buckets[j][bucketCounts[j]] = arr[i];
        bucketCounts[j]++;
    }

    // Sort each bucket and put the elements back into the original array
    for (i = 0; i < numBuckets; i++) {        
        for (j = 0; j < bucketCounts[i]; j++) {            
            for (k = j + 1; k < bucketCounts[i]; k++) {                
                if (buckets[i][j] > buckets[i][k]) {                    
                    // Swap the elements
                    float tempBucket = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = tempBucket;
                }
            }
            arr[count++] = buckets[i][j];
        }
    }

    // Free memory
    for (i = 0; i < numBuckets; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketCounts);
}

int main() {
    int size, i;
    float* arr = NULL;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = (float*)malloc(size * sizeof(float));

    printf("Enter %d elements in the array:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Array before sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }

    bucketSort(arr, size);

    printf("\n\nArray after sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}