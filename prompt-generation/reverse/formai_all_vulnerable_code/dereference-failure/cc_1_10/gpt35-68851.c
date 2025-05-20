//FormAI DATASET v1.0 Category: Sorting ; Style: genious
#include<stdio.h>

void quick_sort(int[],int,int);
int partition(int[],int,int);

int main()
{
  int arr[50],n,i;
  
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  
  printf("Enter the elements of the array:\n");
  
  for(i=0;i<n;i++)
     scanf("%d",&arr[i]);
     
  printf("\nArray before sorting:");
     
  for (i=0;i<n;i++)
      printf("%d ",arr[i]);
  
  quick_sort(arr,0,n-1);
  
  printf("\n\nArray after sorting:");
  
  for(i=0;i<n;i++)
     printf("%d ",arr[i]);
  
  return 0;
}

void quick_sort(int arr[],int low,int high)
{
    int j;
    if(low<high)
    {
        j=partition(arr,low,high);
        quick_sort(arr,low,j-1);
        quick_sort(arr,j+1,high);
    }
}

int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    int temp,j;
    
    for(j=low;j<=high-1;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            
            //swapping arr[i] and arr[j]
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    
    //swapping arr[i+1] and arr[high]
    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    
    return i+1;
}