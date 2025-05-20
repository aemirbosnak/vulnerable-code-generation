//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void drawBoard(int **board)
{
    for(int r = 0; r < MAX_SIZE; r++)
    {
        for(int c = 0; c < MAX_SIZE; c++)
        {
            printf("%c ", board[r][c]);
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

    // Game loop
    int generation = 0;
    while(1)
    {
        drawBoard(board);

        // Calculate the next generation
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

                if(numNeighbors < 2 || numNeighbors > 3)
                {
                    board[r][c] = 0;
                }
                else
                {
                    board[r][c] = 1;
                }
            }
        }

        // Increment the generation
        generation++;

        // Check if the game is over
        if(generation > 10)
        {
            drawBoard(board);
            printf("Game over!\n");
            break;
        }
    }

    // Free the memory
    for(int r = 0; r < MAX_SIZE; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}