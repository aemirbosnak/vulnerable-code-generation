//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void GameOfLife(int **board, int size)
{
    int i, j, k, l, neighbors = 0;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            // Count the number of neighbors
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    if (i + k >= 0 && i + k < size && j + l >= 0 && j + l < size && board[i + k][j + l] == 1)
                    {
                        neighbors++;
                    }
                }
            }

            // Apply the Game of Life rules
            if (board[i][j] == 0 && neighbors == 3)
            {
                board[i][j] = 1;
            }
            else if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3))
            {
                board[i][j] = 0;
            }

            neighbors = 0;
        }
    }

    return;
}

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the board
    board[0][0] = board[1][0] = board[1][1] = 1;

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