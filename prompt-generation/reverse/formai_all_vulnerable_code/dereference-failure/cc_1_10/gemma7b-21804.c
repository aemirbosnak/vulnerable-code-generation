//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int **arr;
    int n, m, i, j, k, l;
    int **rand_arr;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    arr = (int *)malloc(n * m * sizeof(int));
    rand_arr = (int *)malloc(n * m * sizeof(int));

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            arr[i][j] = 0;
            rand_arr[i][j] = rand() % 2;
        }
    }

    k = 0;
    l = 0;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(arr[i][j] == 1 && rand_arr[i][j] == 0)
            {
                arr[i][j] = 2;
                k++;
            }
        }
    }

    printf("The number of percolations is: %d", k);

    free(arr);
    free(rand_arr);

    return 0;
}