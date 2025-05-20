//FormAI DATASET v1.0 Category: Benchmarking ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n, i, j, temp;
    clock_t start, end;
    double time_taken;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; //creating an array of n elements

    //filling the array with random numbers
    srand(time(0));
    for(i=0; i<n; i++)
    {
        arr[i] = rand();
    }

    //printing the unsorted array
    printf("Unsorted array: ");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    //sorting the array using bubble sort
    start = clock(); //start the clock
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock(); //stop the clock

    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    //printing the sorted array
    printf("\nSorted array: ");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    //printing the time taken to sort the array
    printf("\nTime taken to sort the array: %f seconds", time_taken);

    return 0;
}