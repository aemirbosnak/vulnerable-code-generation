//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// defining macro for maximum value
#define MAX_VALUE 1000000

//function to find maximum value in array
int find_max(int* arr, int size) 
{
    int maximum = 0;
    for(int i=0; i<size; i++)
    {
        if(arr[i] > maximum)
            maximum = arr[i];
    }
    return maximum;
}

//function to find minimum value in array
int find_min(int* arr, int size)
{
    int minimum = MAX_VALUE;
    for(int i=0; i<size; i++)
    {
        if(arr[i] < minimum)
            minimum = arr[i];
    }
    return minimum;
}

int main()
{
    int n, i, max, min;
    int *arr;
    printf("Enter the size of array: ");
    scanf("%d",&n);

    srand(time(0));
    arr = (int*)malloc(n*sizeof(int));

    //filling the array with random numbers
    for(i=0; i<n; i++)
    {
        arr[i] = rand()%MAX_VALUE;
    }
    
    //finding maximum and minimum value in array
    max = find_max(arr,n);
    min = find_min(arr,n);

    printf("\nArray elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nMaximum value in array: %d \nMinimum value in array: %d", max, min);

    free(arr);
    return 0;
}