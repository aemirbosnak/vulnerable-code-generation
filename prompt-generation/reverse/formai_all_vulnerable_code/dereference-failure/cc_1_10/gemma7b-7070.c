//Gemma-7B DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void sort(int **arr, int n)
{
    int i, j, k, min_index, temp;
    for (i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j][0] < arr[min_index][0])
            {
                min_index = j;
            }
        }
        temp = arr[min_index][0];
        arr[min_index][0] = arr[i][0];
        arr[i][0] = temp;
    }
}

int main()
{
    int **arr = NULL;
    int n = 0;

    scanf("Enter the number of elements: ", &n);
    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter the two integers: ");
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    sort(arr, n);

    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }

    free(arr);

    return 0;
}