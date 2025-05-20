//Gemma-7B DATASET v1.0 Category: Data mining ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, count = 0, max_count = 0, **arr = NULL;

    scanf("Enter the number of elements: ", &n);

    arr = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("Enter the element at (%d, %d): ", &arr[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            count = 0;
            for (k = 0; k < n; k++)
            {
                for (l = 0; l < n; l++)
                {
                    if (arr[i][j] == arr[k][l])
                    {
                        count++;
                    }
                }
            }

            if (count > max_count)
            {
                max_count = count;
            }
        }
    }

    printf("The maximum number of occurrences of an element is: %d", max_count);

    return 0;
}