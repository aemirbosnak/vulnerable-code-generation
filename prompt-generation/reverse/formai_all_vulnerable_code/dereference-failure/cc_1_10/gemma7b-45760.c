//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 10

void shuffle(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int r = rand() % n;
        int temp = arr[i];
        arr[i] = arr[r];
        arr[r] = temp;
    }
}

int main()
{
    int **arr = (int **)malloc(MAX_NUMBER * sizeof(int *));
    for (int i = 0; i < MAX_NUMBER; i++)
    {
        arr[i] = (int *)malloc(MAX_NUMBER * sizeof(int));
    }

    int n = MAX_NUMBER;
    time_t t = time(NULL);
    srand(t);

    shuffle(arr, n);

    printf("The array is shuffled.\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                printf("%d ", arr[i][j]);
            }
            else
            {
                printf("%d ", arr[i][j] - 1);
            }
        }
        printf("\n");
    }

    free(arr);

    return 0;
}