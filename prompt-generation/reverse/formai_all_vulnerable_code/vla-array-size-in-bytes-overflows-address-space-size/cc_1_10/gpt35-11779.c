//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include<stdio.h>
#include<stdlib.h>

#define MAX_VALUE 1000
#define BUCKET_SIZE 10

void printArray(int [],int);
void bucketSort(int [],int);

int main()
{
    int arr[MAX_VALUE],n;

    printf("Enter number of elements to sort: ");
    scanf("%d",&n);

    printf("Enter elements of array seperated by space: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nOriginal Array: ");
    printArray(arr,n);

    bucketSort(arr,n);

    printf("\nSorted Array: ");
    printArray(arr,n);

    return 0;
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

void bucketSort(int arr[],int n)
{
    int max_value=arr[0];

    for(int i=1;i<n;i++)
    {
        if(arr[i]>max_value)
        {
            max_value=arr[i];
        }
    }

    int num_buckets=(max_value/BUCKET_SIZE)+1;
    int buckets[num_buckets];

    for(int i=0;i<num_buckets;i++)
    {
        buckets[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        int bucket_index=arr[i]/BUCKET_SIZE;
        buckets[bucket_index]++;
    }

    int current_index=0;
    for(int i=0;i<num_buckets;i++)
    {
        int count=buckets[i];
        for(int j=0;j<count;j++)
        {
            arr[current_index++]=i*BUCKET_SIZE;
        }
    }

    for(int i=0;i<num_buckets;i++)
    {
        int bucket_start_index=i*BUCKET_SIZE;
        int bucket_end_index=(i+1)*BUCKET_SIZE-1;
        for(int j=bucket_start_index;j<=bucket_end_index;j++)
        {
            if(arr[j]>bucket_end_index)
            {
                int temp=arr[j];
                int new_bucket_index=temp/BUCKET_SIZE;
                buckets[new_bucket_index]++;
                arr[j]=buckets[new_bucket_index]*BUCKET_SIZE+(temp%BUCKET_SIZE);
            }
        }

        for(int j=bucket_start_index;j<=bucket_end_index;j++)
        {
            int bucket_index=arr[j]/BUCKET_SIZE;
            buckets[bucket_index]--;
        }
    }
}