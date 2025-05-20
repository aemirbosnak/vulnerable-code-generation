//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void printBoard(int **board)
{
    for(int r = 0; r < MAX_SIZE; r++)
    {
        for(int c = 0; c < MAX_SIZE; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for(int r = 0; r < MAX_SIZE; r++)
    {
        board[r] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    for(int r = 0; r < MAX_SIZE; r++)
    {
        for(int c = 0; c < MAX_SIZE; c++)
        {
            board[r][c] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create random patterns
    for(int i = 0; i < 10; i++)
    {
        int r = rand() % MAX_SIZE;
        int c = rand() % MAX_SIZE;
        board[r][c] = 1;
    }

    // Print the initial board
    printBoard(board);

    // Simulate game of life
    for(int t = 0; t < 20; t++)
    {
        // Calculate the next generation
        int **nextBoard = (int **)malloc(MAX_SIZE * sizeof(int *));
        for(int r = 0; r < MAX_SIZE; r++)
        {
            nextBoard[r] = (int *)malloc(MAX_SIZE * sizeof(int));
        }

        for(int r = 0; r < MAX_SIZE; r++)
        {
            for(int c = 0; c < MAX_SIZE; c++)
            {
                int numNeighbors = 0;
                for(int dr = -1; dr <= 1; dr++)
                {
                    for(int dc = -1; dc <= 1; dc++)
                    {
                        if(board[r + dr][c + dc] == 1)
                        {
                            numNeighbors++;
                        }
                    }
                }

                nextBoard[r][c] = (numNeighbors == 2) || (numNeighbors == 3);
            }
        }

        // Free the previous board
        for(int r = 0; r < MAX_SIZE; r++)
        {
            free(board[r]);
        }
        free(board);

        // Update the board
        board = nextBoard;

        // Print the current board
        printBoard(board);
    }

    // Free the final board
    for(int r = 0; r < MAX_SIZE; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}