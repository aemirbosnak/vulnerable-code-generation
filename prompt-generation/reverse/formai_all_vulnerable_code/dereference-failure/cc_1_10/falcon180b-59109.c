//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main()
{
    int *arr = malloc(MAX_SIZE * sizeof(int));
    int i, j;

    srand(time(NULL));

    for (i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = rand() % 100;
    }

    printf("Before Sorting:\n");
    for (i = 0; i < MAX_SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int start_time = clock();
    for (i = 0; i < MAX_SIZE - 1; i++)
    {
        for (j = 0; j < MAX_SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int end_time = clock();

    printf("After Sorting:\n");
    for (i = 0; i < MAX_SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Time taken for sorting: %lf seconds\n", time_taken);

    free(arr);
    return 0;
}