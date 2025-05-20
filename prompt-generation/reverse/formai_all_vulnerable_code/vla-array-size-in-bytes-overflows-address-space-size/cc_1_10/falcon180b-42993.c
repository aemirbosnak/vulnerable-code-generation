//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 1000

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n)
{
    int i, j, k, max = 0, min = 0, range, index;
    int *bucket[MAX];
    for(i = 0; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
        else if(arr[i] < min)
            min = arr[i];
    }
    range = max - min + 1;
    for(i = 0; i < range; i++)
    {
        bucket[i] = (int*)malloc(n * sizeof(int));
    }
    for(i = 0; i < n; i++)
    {
        index = (arr[i] - min) * n / range;
        if(index == n)
            index = n - 1;
        bucket[index] = (int*)realloc(bucket[index], sizeof(int) * (k + 1));
        bucket[index][k] = arr[i];
        k++;
    }
    for(i = 0; i < n; i++)
    {
        index = (arr[i] - min) * n / range;
        if(index == n)
            index = n - 1;
        arr[i] = bucket[index][k - 1];
        k--;
    }
    for(i = 0; i < range; i++)
    {
        free(bucket[i]);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int i, n;
    srand(time(0));
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Unsorted array: ");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}