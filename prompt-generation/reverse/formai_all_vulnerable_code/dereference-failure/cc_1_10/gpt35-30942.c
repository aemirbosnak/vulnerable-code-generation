//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

void bucketSort(float arr[], int n)
{
    int i, j;
    float *bucket, minVal = arr[0], maxVal = arr[0];

    // Find minimum and maximum values in the given array
    for(i = 1; i < n; i++)
    {
        minVal = minVal < arr[i] ? minVal : arr[i];
        maxVal = maxVal > arr[i] ? maxVal : arr[i];
    }

    // Allocate memory for buckets
    bucket = (float*)malloc(sizeof(float)*(maxVal - minVal + 1)); 

    // Initialize all the buckets to 0
    for(i = 0; i < maxVal - minVal + 1; i++)
        bucket[i] = 0; 

    // Put elements into the buckets
    for(i = 0; i < n; i++)
        bucket[(int)(arr[i] - minVal)]++; 

    // Sort elements from the buckets
    for(i = 0, j = 0; i < maxVal - minVal + 1; i++)
    {
        while(bucket[i] > 0)
        {
            arr[j++] = i + minVal;
            bucket[i]--;
        }
    }

    // Free dynamically allocated memory
    free(bucket);
}

int main()
{
    int i, n;
    float *arr;

    printf("Enter size of array: ");
    scanf("%d", &n);

    // Allocate memory for array
    arr = (float*)malloc(sizeof(float)*n);

    // Read array elements from user
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print sorted array
    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    // Free dynamically allocated memory
    free(arr);

    return 0;
}