//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: imaginative
#include <stdio.h>

void GameOfLife(int **board, int size)
{
    int i, j, k, l, neighbor_count;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            neighbor_count = 0;
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    if (k == 0 && l == 0)
                        continue;
                    if (board[i + k][j + l] == 1)
                        neighbor_count++;
                }
            }
            if (board[i][j] == 1 && neighbor_count < 2)
                board[i][j] = 0;
            else if (board[i][j] == 0 && neighbor_count == 3)
                board[i][j] = 1;
        }
    }
}

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
    }

    // Initial board setup
    board[1][1] = board[2][2] = board[2][3] = 1;

    // Game of Life iterations
    for (int iter = 0; iter < 10; iter++)
    {
        GameOfLife(board, size);
    }

    // Print final board
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