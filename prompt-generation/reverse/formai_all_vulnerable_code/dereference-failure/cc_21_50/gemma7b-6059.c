//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main()
{
    int **board = NULL;
    int i, j, k, l, r, s, n;

    // Allocate memory for the board
    board = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Initialize the board
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            board[i][j] = 0;
        }
    }

    // Seed the board with random values
    s = 10;
    n = MAX * MAX;
    for (k = 0; k < n; k++)
    {
        board[rand() % MAX][rand() % MAX] = 1;
    }

    // Simulate the Game of Life
    for (r = 0; r < MAX; r++)
    {
        for (l = 0; l < MAX; l++)
        {
            // Count the number of neighbors
            int neighbors = 0;
            for (i = -1; i <= 1; i++)
            {
                for (j = -1; j <= 1; j++)
                {
                    if (board[i][j] && (i != r || j != l))
                    {
                        neighbors++;
                    }
                }
            }

            // Apply the Game of Life rules
            if (board[r][l] && neighbors < 2)
            {
                board[r][l] = 0;
            }
            else if (board[r][l] && neighbors > 3)
            {
                board[r][l] = 0;
            }
            else if (board[r][l] == 0 && neighbors == 3)
            {
                board[r][l] = 1;
            }
        }
    }

    // Print the final board
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < MAX; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}