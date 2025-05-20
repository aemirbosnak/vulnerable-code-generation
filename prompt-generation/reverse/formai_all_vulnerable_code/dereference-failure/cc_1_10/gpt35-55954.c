//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(float array[], int n)
{
    int i, j;
    float temp;
    int count = 0;
    int bucket_count = 10;
    int* bucket = NULL; 

    bucket = (int*)calloc(bucket_count, sizeof(int));

    for (i = 0; i < n; ++i)
    {
        ++bucket[(int)array[i]];
    }

    for (i = 0; i < bucket_count; i++)
    {
        count += bucket[i];
    }

    for (i = 0, j = 0; j < bucket_count; j++)
    {
        while (bucket[j] > 0)
        {
            array[i++] = j;
            bucket[j]--;
        }
    }

    free(bucket);
}

int main()
{
    int n, i;
    float array[100];

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &array[i]);
    }

    bucket_sort(array, n);

    printf("The sorted array is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%f ", array[i]);
    }

    return 0;
}