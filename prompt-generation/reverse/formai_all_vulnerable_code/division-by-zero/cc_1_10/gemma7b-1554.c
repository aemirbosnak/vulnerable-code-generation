//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int main()
{
    int n, m, i, j, k, l, r, x, y, z;
    char board[MAX][MAX];
    srand(time(NULL));

    n = rand() % MAX;
    m = rand() % MAX;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            board[i][j] = '.';
        }
    }

    board[n / 2][m / 2] = 'O';

    k = 0;
    l = 0;
    r = n - 1;
    y = m - 1;

    while (k < n && l < y)
    {
        x = rand() % (r - l + 1) + l;
        y = rand() % (y - k + 1) + k;

        if (board[x][y] == '.')
        {
            board[x][y] = 'O';
            k++;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}