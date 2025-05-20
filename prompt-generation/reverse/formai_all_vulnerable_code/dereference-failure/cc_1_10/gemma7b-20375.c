//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void game_of_life(int **board, int size)
{
    int i, j, k, l, alive_neighbors = 0;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            // Count alive neighbors
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    if (k == 0 && l == 0)
                        continue;

                    if (board[i + k][j + l] == 1)
                        alive_neighbors++;
                }
            }

            // Apply rules of survival
            if (board[i][j] == 1 && alive_neighbors < 2)
                board[i][j] = 0;
            else if (board[i][j] == 0 && alive_neighbors == 3)
                board[i][j] = 1;
            alive_neighbors = 0;
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

    // Initial board setup
    board[1][1] = board[2][2] = board[2][3] = 1;

    // Game of Life simulation
    game_of_life(board, size);

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