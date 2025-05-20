//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void GameOfLife(int **board, int size)
{
    int i, j, k, l, neighbors = 0;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            neighbors = 0;
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    if (k == 0 && l == 0)
                        continue;

                    if (board[i + k][j + l] == 1)
                        neighbors++;
                }
            }

            if (board[i][j] == 1)
            {
                if (neighbors < 2 || neighbors > 3)
                    board[i][j] = 0;
            }
            else
            {
                if (neighbors == 3)
                    board[i][j] = 1;
            }
        }
    }
}

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
        board[i] = (int *)malloc(size * sizeof(int));

    // Initial board
    board[1][1] = board[2][2] = board[2][3] = board[3][2] = 1;

    GameOfLife(board, size);

    // Print the final board
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}