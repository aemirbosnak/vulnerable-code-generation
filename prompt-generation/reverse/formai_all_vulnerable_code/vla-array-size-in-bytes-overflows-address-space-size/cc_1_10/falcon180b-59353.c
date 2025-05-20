//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_SIZE 100000
#define MAX_NUM 1000000

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n)
{
    int i,j,k,max;
    int bucket[MAX_NUM];
    for(i=0;i<MAX_NUM;i++)
        bucket[i] = 0;
    for(i=0;i<n;i++)
    {
        if(arr[i] < 0)
            arr[i] *= -1;
        max = arr[i] / 10;
        bucket[max]++;
    }
    for(i=1;i<MAX_NUM;i++)
        bucket[i] += bucket[i-1];
    for(i=n-1;i>=0;i--)
    {
        j = arr[i] / 10;
        k = bucket[j] - 1;
        bucket[j]--;
        arr[k] = arr[i];
    }
}

void printArray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d integers:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    srand(time(NULL));
    for(i=0;i<n;i++)
        arr[i] = rand() % MAX_NUM;
    printf("Before Sorting:\n");
    printArray(arr,n);
    bucketSort(arr,n);
    printf("After Sorting:\n");
    printArray(arr,n);
    return 0;
}