//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: complex
#include<stdio.h>
#include<stdlib.h>

// Defining the maximum and minimum values of the input array
#define MAX_VALUE 100
#define MIN_VALUE 0

void bucketSort(int a[], int n)
{
    // Creating buckets of arrays
    int bucket[MAX_VALUE - MIN_VALUE + 1];

    // Initialize bucket with 0
    for(int i = 0; i < MAX_VALUE - MIN_VALUE + 1; i++)
    {
        bucket[i] = 0;
    }

    // Store the occurence of each element into bucket array
    for(int i = 0; i < n; i++)
    {
        bucket[a[i] - MIN_VALUE]++;
    }

    // Sort the array elements using the bucket array
    int j = 0;
    for(int i = MIN_VALUE; i <= MAX_VALUE; i++)
    {
        while(bucket[i - MIN_VALUE] > 0)
        {
            a[j++] = i;
            bucket[i - MIN_VALUE]--;
        }
    }
}

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Array before sorting: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    bucketSort(a, n);

    printf("\nArray after sorting: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\n");

    return 0;
}