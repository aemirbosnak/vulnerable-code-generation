//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: sophisticated
#include <stdlib.h>
#include <time.h>

#define DIM 10

int main()
{
    int **arr = NULL;
    int **percolation_array = NULL;
    int i, j, k, rand_num;

    arr = (int**)malloc(DIM * sizeof(int*));
    percolation_array = (int**)malloc(DIM * sizeof(int*));

    for(i = 0; i < DIM; i++)
    {
        arr[i] = (int*)malloc(DIM * sizeof(int));
        percolation_array[i] = (int*)malloc(DIM * sizeof(int));
    }

    srand(time(NULL));

    for(i = 0; i < DIM; i++)
    {
        for(j = 0; j < DIM; j++)
        {
            arr[i][j] = rand() % 2;
            percolation_array[i][j] = 0;
        }
    }

    for(k = 0; k < 1000; k++)
    {
        rand_num = rand() % DIM;
        i = rand_num / DIM;
        j = rand_num % DIM;

        if(arr[i][j] == 1 && percolation_array[i][j] == 0)
        {
            percolation_array[i][j] = 1;
        }
    }

    for(i = 0; i < DIM; i++)
    {
        for(j = 0; j < DIM; j++)
        {
            printf("%d ", percolation_array[i][j]);
        }
        printf("\n");
    }

    free(arr);
    free(percolation_array);

    return 0;
}