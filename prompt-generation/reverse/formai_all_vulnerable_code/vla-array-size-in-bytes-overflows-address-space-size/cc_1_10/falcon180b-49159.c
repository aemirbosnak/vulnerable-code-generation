//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

void bucket_sort(int arr[], int n)
{
    int i,j;
    int max_val = arr[0];
    int min_val = arr[0];
    int *bucket[MAX];
    for(i=0;i<MAX;i++)
    {
        bucket[i] = malloc(n*sizeof(int));
    }
    for(i=0;i<n;i++)
    {
        if(arr[i] > max_val)
        {
            max_val = arr[i];
        }
        if(arr[i] < min_val)
        {
            min_val = arr[i];
        }
    }
    int bucket_size = (max_val-min_val)/(MAX*1.0);
    for(i=0;i<n;i++)
    {
        j = (arr[i] - min_val)/bucket_size;
        bucket[j] = realloc(bucket[j], (j+1)*sizeof(int));
        bucket[j][j] = arr[i];
    }
    int k = 0;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<=bucket[i][0];j++)
        {
            arr[k++] = bucket[i][j];
        }
    }
    for(i=0;i<MAX;i++)
    {
        free(bucket[i]);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    bucket_sort(arr,n);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}