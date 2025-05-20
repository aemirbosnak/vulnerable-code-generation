//FormAI DATASET v1.0 Category: Searching algorithm ; Style: brave
#include<stdio.h>

void printArray(int Arr[], int Size)
{
    for(int i=0;i<Size;i++)
        printf("%d ",Arr[i]);
    printf("\n");
}

void insertionSort(int Arr[], int Size)
{
    for(int i=1;i<Size;i++)
    {
        int temp = Arr[i];
        int j = i-1;
        while(j>=0 && Arr[j]>temp)
        {
            Arr[j+1] = Arr[j];
            j--;
        }
        Arr[j+1] = temp;
    }
}

int binarySearch(int Arr[], int Size, int key)
{
    int first = 0;
    int last = Size-1;
    int middle = (first+last)/2;
    while(first<=last)
    {
        if(Arr[middle]<key)
            first = middle+1;
        else if(Arr[middle]==key)
            return middle;
        else
            last = middle-1;
        middle = (first+last)/2;
    }
    return -1;
}

int main()
{
    int n,key,result;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Array before sorting: ");
    printArray(arr,n);
    insertionSort(arr,n);
    printf("Array after sorting: ");
    printArray(arr,n);
    printf("Enter the key to search: ");
    scanf("%d",&key);
    result = binarySearch(arr,n,key);
    if(result==-1)
        printf("Element is not present in the array.\n");
    else
        printf("Element is present at index %d.\n",result);
    return 0;
}