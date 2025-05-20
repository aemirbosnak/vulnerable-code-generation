//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Function to sort an array of float numbers using bucket sort
void bucketSort(float arr[], int n, int num_buckets)
{
    // Create num_buckets empty buckets
    int i, j;
    int counts[num_buckets];
    float** buckets = (float**)malloc(num_buckets * sizeof(float*));
    for (i = 0; i < num_buckets; i++){
        counts[i] = 0;
        buckets[i] = (float*)malloc(n * sizeof(float));
    }
 
    // Put array elements in different buckets
    for (i = 0; i < n; i++) {
        int bucket_idx = (int)(arr[i] * num_buckets);
        buckets[bucket_idx][counts[bucket_idx]] = arr[i];
        counts[bucket_idx]++;
    }
 
    // Sort individual buckets
    for (i = 0; i < num_buckets; i++) {
        for (j = 0; j < counts[i]; j++) {
            int k;
            float temp = buckets[i][j];
            for (k = j; k > 0 && buckets[i][k - 1] > temp; k--)
                buckets[i][k] = buckets[i][k - 1];
            buckets[i][k] = temp;
        }
    }
 
    // Concatenate all buckets into arr[]
    int idx = 0;
    for (i = 0; i < num_buckets; i++) {
        for (j = 0; j < counts[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
        free(buckets[i]);
    }
    free(buckets);
}
 
// Driver program to test above function
int main()
{
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num_buckets = 5;
    bucketSort(arr, n, num_buckets);
 
    printf("Sorted array is: \n");
    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);
    return 0;
}