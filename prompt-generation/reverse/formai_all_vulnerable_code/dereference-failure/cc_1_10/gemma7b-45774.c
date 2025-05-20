//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: complete
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 50

void percol_sim(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == 1)
            {
                int r = rand() % 4;
                switch (r)
                {
                    case 0:
                        arr[i][j] = 0;
                        break;
                    case 1:
                        if (i > 0)
                            arr[i - 1][j] = 1;
                        break;
                    case 2:
                        if (j > 0)
                            arr[i][j - 1] = 1;
                        break;
                    case 3:
                        if (i < size - 1)
                            arr[i + 1][j] = 1;
                        break;
                }
            }
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **arr = (int **)malloc(size * size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++)
            arr[i][j] = 0;
    }

    percol_sim(arr, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    return 0;
}