//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

/* Define the bucket sort function */
void bucketSort(float arr[], int n)
{
    /* Create the buckets */
    int i, j, k;
    int numBuckets = 10;
    float div = (float)(n/10.0) + 1;
    int sizes[10] = {0};
    float **buckets = (float**)malloc(numBuckets * sizeof(float*));
    for(i = 0; i < numBuckets; i++){
        buckets[i] = (float*)malloc(div * sizeof(float));
    }

    /* Sort into buckets */
    for(i = 0; i < n; i++){
        int index = (int)(arr[i] * numBuckets);
        buckets[index][sizes[index]++] = arr[i];
    }

    /* Sort each bucket and combine back into one array */
    for(i = 0; i < numBuckets; i++){
        for(j = 1; j < sizes[i]; j++){
            float temp = buckets[i][j];
            k = j - 1;
            while(k >= 0 && buckets[i][k] > temp){
                buckets[i][k+1] = buckets[i][k];
                k--;
            }
            buckets[i][k+1] = temp;
        }
    }

    /* Combine the buckets */
    int m = 0;
    for(i = 0; i < numBuckets; i++){
        for(j = 0; j < sizes[i]; j++){
            arr[m++] = buckets[i][j];
        }
        free(buckets[i]);
    }
    free(buckets);
}

/* Main function */
int main()
{
    /* Initialize the array */
    int n = 10;
    float arr[] = {0.35, 0.58, 0.74, 0.2, 0.16, 0.46, 0.36, 0.77, 0.98, 0.68};

    /* Sort the array */
    bucketSort(arr, n);

    /* Print the sorted array */
    for(int i = 0; i < n; i++){
        printf("%f ", arr[i]);
    }

    return 0;
}