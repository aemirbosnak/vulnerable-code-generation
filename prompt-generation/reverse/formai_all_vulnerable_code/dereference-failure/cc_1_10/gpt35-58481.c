//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUCKET_SIZE 10

int* bucketSort(int* arr, int size)
{
    int i, j;
    int* bucket = calloc(BUCKET_SIZE, sizeof(int));

    for(i = 0; i < size; i++)
    {
        (bucket[arr[i]/BUCKET_SIZE])++;
    }

    int index = 0;
    for(i = 0; i < BUCKET_SIZE; i++)
    {
        for(j = 0; j < bucket[i]; j++)
        {
            arr[index++] = (i * BUCKET_SIZE) + j;
        }
    }

    return arr;
}

int main()
{
    srand(time(NULL));
    int i, size;

    printf("\n\t~Bucket Sort Example Program~\n");

    printf("Enter the number of elements that you want to sort: ");
    scanf("%d", &size);

    int* arr = calloc(size, sizeof(int));
    printf("\nEnter the elements: ");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n***Original Array***\n");
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    arr = bucketSort(arr, size);

    printf("\n\n***Bucket Sorted Array***\n");
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\n***End of Program***\n");

    free(arr);
    return 0;
}