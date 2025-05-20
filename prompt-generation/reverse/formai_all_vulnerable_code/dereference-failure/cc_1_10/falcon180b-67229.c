//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define RANGE 100

int main()
{
    int i, j, n, max, min, range, *arr;
    int *bucket[MAX_SIZE];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    range = max - min + 1;
    printf("Range: %d\n", range);

    for (i = 0; i < MAX_SIZE; i++)
    {
        bucket[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        j = (arr[i] - min) / range * MAX_SIZE;
        bucket[j] = realloc(bucket[j], (++bucket[j][0]) * sizeof(int));
        bucket[j][bucket[j][0] - 1] = arr[i];
    }

    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < bucket[i][0]; j++)
        {
            printf("%d ", bucket[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < MAX_SIZE; i++)
    {
        free(bucket[i]);
    }
    free(arr);

    return 0;
}