//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

int main()
{
    int i, j, n;
    int *arr = (int *)malloc(MAX*sizeof(int));
    int *bucket = (int *)malloc(MAX*sizeof(int));
    int max = 0, min = 9999;
    clock_t start, end;
    double cpu_time_used;

    //initialize the array with random values
    srand(time(NULL));
    for(i=0; i<MAX; i++)
    {
        arr[i] = rand()%100;
    }

    //find the maximum and minimum values
    for(i=0; i<MAX; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        else if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    //calculate the range and bucket size
    int range = max - min + 1;
    int bucket_size = range / MAX;

    //initialize the buckets
    for(i=0; i<MAX; i++)
    {
        bucket[i] = 0;
    }

    //distribute the elements into the buckets
    for(i=0; i<MAX; i++)
    {
        int bucket_index = (arr[i] - min) / bucket_size;
        bucket[bucket_index]++;
    }

    //sort the elements in the buckets
    for(i=0; i<MAX; i++)
    {
        int k = 0;
        for(j=0; j<bucket[i]; j++)
        {
            arr[k++] = i*bucket_size + j*bucket_size + min;
        }
    }

    //print the sorted array
    printf("Sorted array:\n");
    for(i=0; i<MAX; i++)
    {
        printf("%d ", arr[i]);
    }

    //free the memory
    free(arr);
    free(bucket);

    return 0;
}