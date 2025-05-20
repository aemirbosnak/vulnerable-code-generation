//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, n, m, i, j, flag = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    int **arr = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }

    printf("Enter the number of bombs: ");
    scanf("%d", &i);

    for(j = 0; j < i; j++)
    {
        printf("Enter the row of the bomb: ");
        scanf("%d", &x);

        printf("Enter the column of the bomb: ");
        scanf("%d", &y);

        arr[x][y] = 1;
    }

    printf("Enter the number of moves: ");
    scanf("%d", &i);

    for(j = 0; j < i; j++)
    {
        printf("Enter the row of the move: ");
        scanf("%d", &x);

        printf("Enter the column of the move: ");
        scanf("%d", &y);

        if(arr[x][y] == 1)
        {
            flag = 1;
            break;
        }
    }

    if(flag)
    {
        printf("Game Over!\n");
    }
    else
    {
        printf("You won!\n");
    }

    free(arr);

    return 0;
}