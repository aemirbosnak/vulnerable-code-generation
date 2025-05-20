//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void GameOfLife(int ***board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            int neighbors = 0;
            for (int dr = -1; dr <= 1; dr++)
            {
                for (int dc = -1; dc <= 1; dc++)
                {
                    if (dr == 0 && dc == 0)
                        continue;
                    if (board[r + dr][c + dc] == 1)
                        neighbors++;
                }
            }

            if (board[r][c] == 0 && neighbors == 3)
                board[r][c] = 1;
            else if (board[r][c] == 1 && (neighbors < 2 || neighbors > 3))
                board[r][c] = 0;
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int r = 0; r < size; r++)
    {
        board[r] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the board
    board[0][0] = 1;
    board[0][1] = 1;
    board[1][0] = 1;
    board[1][1] = 1;

    // Run the game for 10 iterations
    for (int i = 0; i < 10; i++)
    {
        GameOfLife(board, size);
    }

    // Print the final board
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int r = 0; r < size; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}