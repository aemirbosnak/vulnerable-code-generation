//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 20
#define MAX_COLS 20

void displayBoard(int **board)
{
    for (int r = 0; r < MAX_ROWS; r++)
    {
        for (int c = 0; c < MAX_COLS; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(MAX_ROWS * sizeof(int *));
    for (int r = 0; r < MAX_ROWS; r++)
    {
        board[r] = (int *)malloc(MAX_COLS * sizeof(int));
    }

    // Initialize the board with random values
    for (int r = 0; r < MAX_ROWS; r++)
    {
        for (int c = 0; c < MAX_COLS; c++)
        {
            board[r][c] = rand() % 2;
        }
    }

    // Display the initial board
    displayBoard(board);

    // Simulate game of life for 10 generations
    for (int gen = 0; gen < 10; gen++)
    {
        // Calculate the next generation of cells
        int **nextBoard = (int **)malloc(MAX_ROWS * sizeof(int *));
        for (int r = 0; r < MAX_ROWS; r++)
        {
            nextBoard[r] = (int *)malloc(MAX_COLS * sizeof(int));
        }

        for (int r = 0; r < MAX_ROWS; r++)
        {
            for (int c = 0; c < MAX_COLS; c++)
            {
                int numNeighbors = 0;
                // Check the number of neighbors for each cell
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] == 1)
                        {
                            numNeighbors++;
                        }
                    }
                }

                // Set the next generation cell value based on the number of neighbors
                nextBoard[r][c] = (numNeighbors == 2 || numNeighbors == 3) ? 1 : 0;
            }
        }

        // Display the next generation board
        displayBoard(nextBoard);

        // Free the memory used by the next generation board
        for (int r = 0; r < MAX_ROWS; r++)
        {
            free(nextBoard[r]);
        }
        free(nextBoard);

        // Update the board with the next generation
        for (int r = 0; r < MAX_ROWS; r++)
        {
            for (int c = 0; c < MAX_COLS; c++)
            {
                board[r][c] = nextBoard[r][c];
            }
        }
    }

    // Display the final board
    displayBoard(board);

    // Free the memory used by the board
    for (int r = 0; r < MAX_ROWS; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}