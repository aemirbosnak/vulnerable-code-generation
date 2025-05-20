//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **board = NULL;
    int rows, cols;
    int i, j, k, l;

    // Allocate memory for the game board
    board = (char **)malloc(sizeof(char *) * 10);
    for (i = 0; i < 10; i++)
    {
        board[i] = (char *)malloc(sizeof(char) * 20);
    }

    // Initialize the game board
    rows = 10;
    cols = 20;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = '-';
        }
    }

    // Set the initial cells to alive
    board[1][2] = 'o';
    board[2][3] = 'o';
    board[3][4] = 'o';
    board[4][5] = 'o';

    // Game loop
    while (1)
    {
        // Print the game board
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Calculate the next generation
        for (k = 0; k < rows; k++)
        {
            for (l = 0; l < cols; l++)
            {
                int numAliveNeighbors = 0;
                if (k > 0)
                {
                    if (board[k - 1][l] == 'o')
                    {
                        numAliveNeighbors++;
                    }
                }
                if (k < rows - 1)
                {
                    if (board[k + 1][l] == 'o')
                    {
                        numAliveNeighbors++;
                    }
                }
                if (l > 0)
                {
                    if (board[k][l - 1] == 'o')
                    {
                        numAliveNeighbors++;
                    }
                }
                if (l < cols - 1)
                {
                    if (board[k][l + 1] == 'o')
                    {
                        numAliveNeighbors++;
                    }
                }

                // Apply the rules of survival and reproduction
                if (board[k][l] == 'o' && numAliveNeighbors < 2)
                {
                    board[k][l] = '-';
                }
                else if (board[k][l] == '-' && numAliveNeighbors == 3)
                {
                    board[k][l] = 'o';
                }
            }
        }

        // Check if the game is over
        if (board[0][0] == 'o' || board[rows - 1][cols - 1] == 'o')
        {
            break;
        }
    }

    // Free the memory allocated for the game board
    for (i = 0; i < 10; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}