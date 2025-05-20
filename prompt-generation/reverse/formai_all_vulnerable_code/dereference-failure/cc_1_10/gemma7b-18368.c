//Gemma-7B DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

int main()
{
    int i, j, k, l, n, m, count = 0, max_count = 0, **arr = NULL;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    arr = (int **)malloc(n * sizeof(int *) + m * sizeof(int));

    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter the elements of the matrix: ");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            count = 0;
            for (k = 0; k < n; k++)
            {
                for (l = 0; l < m; l++)
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

    printf("The maximum number of occurrences of an element in the matrix is: %d", max_count);

    return 0;
}