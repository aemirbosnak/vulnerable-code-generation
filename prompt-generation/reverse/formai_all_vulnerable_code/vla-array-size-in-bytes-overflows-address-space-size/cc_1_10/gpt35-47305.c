//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

void bucket_sort(int arr[], int n)
{
    // Create an array of buckets
    int buckets[100];

    // Initialize all buckets to 0
    for(int i=0; i<100; i++)
    {
        buckets[i] = 0;
    }
    
    // Increment the respective bucket's count for each element in the input array
    for(int i=0; i<n; i++)
    {
        int index = arr[i]/4;
        buckets[index]++;
    }

    // Sort each bucket using Insertion Sort
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<buckets[i]; j++)
        {
            for(int k=j+1; k<buckets[i]; k++)
            {
                if(arr[j+(i*4)]>arr[k+(i*4)])
                {
                    int temp = arr[j+(i*4)];
                    arr[j+(i*4)] = arr[k+(i*4)];
                    arr[k+(i*4)] = temp;
                }
            }
        }
    }
}

int main()
{
    // Get input array from user
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Call bucket sort function
    bucket_sort(arr, n);

    // Print the sorted array
    printf("Sorted Array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}