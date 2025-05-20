//FormAI DATASET v1.0 Category: Sorting ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quickSort(int[],int,int);
int partition(int[],int,int);

int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d",&n); 

    int arr[n];
    srand(time(0)); // to generate random numbers

    printf("\nUnsorted array is: ");
    for(i=0;i<n;i++)
    {
        arr[i] = rand()%100; // array of random numbers
        printf("%d ",arr[i]);
    }

    quickSort(arr,0,n-1);

    printf("\nSorted array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}

void quickSort(int arr[],int low,int high)
{
    if(low < high)
    {
        int pivot = partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}

int partition(int arr[],int low,int high)
{
    int pivot = arr[low]; // pivot as first element
    int i = low+1, j = high, temp;

    while(i <= j)
    {
        while(arr[i]<=pivot) // next element greater than pivot
            i++;
        while(arr[j]>pivot) // next element less or equal to pivot
            j--;
        if(i<j) // swapping elements
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    temp=arr[low]; // placing pivot in correct position
    arr[low]=arr[j];
    arr[j]=temp;

    return j;
}