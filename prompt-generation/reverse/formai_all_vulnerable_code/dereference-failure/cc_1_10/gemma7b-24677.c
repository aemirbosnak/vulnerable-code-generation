//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: protected
#include <stdio.h>
#include <stdlib.h>

void drawBoard(int **board, int size)
{
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            printf("%c ", board[r][c] == 0 ? '.' : 'O');
        }
        printf("\n");
    }
}

int main()
{
    int size = 5;
    int **board = (int**)malloc(size * sizeof(int*));
    for(int r = 0; r < size; r++)
    {
        board[r] = (int*)malloc(size * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Place some random 'O's on the board
    for(int i = 0; i < 10; i++)
    {
        int r = rand() % size;
        int c = rand() % size;
        board[r][c] = 1;
    }

    // Draw the initial board
    drawBoard(board, size);

    // Simulate the game of life
    for(int t = 0; t < 10; t++)
    {
        // Calculate the next generation of cells
        for(int r = 0; r < size; r++)
        {
            for(int c = 0; c < size; c++)
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

                if(board[r][c] == 1)
                {
                    if(numNeighbors < 2 || numNeighbors > 3)
                    {
                        board[r][c] = 0;
                    }
                }
                else
                {
                    if(numNeighbors == 3)
                    {
                        board[r][c] = 1;
                    }
                }
            }
        }

        // Draw the current board
        drawBoard(board, size);
    }

    // Free the memory allocated for the board
    for(int r = 0; r < size; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}