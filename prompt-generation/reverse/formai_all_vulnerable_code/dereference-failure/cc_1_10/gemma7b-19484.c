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
            printf("%c ", board[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int**)malloc(MAX_SIZE * sizeof(int*));
    for(int r = 0; r < MAX_SIZE; r++)
    {
        board[r] = (int*)malloc(MAX_SIZE * sizeof(int));
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

    // Place the initial organisms
    board[5][5] = 1;
    board[4][4] = 1;
    board[3][3] = 1;

    // Run the game for 10 generations
    for(int gen = 0; gen < 10; gen++)
    {
        drawBoard(board);

        // Calculate the next generation
        for(int r = 0; r < MAX_SIZE; r++)
        {
            for(int c = 0; c < MAX_SIZE; c++)
            {
                int numAliveNeighbors = 0;
                for(int dr = -1; dr <= 1; dr++)
                {
                    for(int dc = -1; dc <= 1; dc++)
                    {
                        if(board[r + dr][c + dc] && board[r + dr][c + dc] != -1)
                        {
                            numAliveNeighbors++;
                        }
                    }
                }

                if(board[r][c] == 1 && numAliveNeighbors < 2)
                {
                    board[r][c] = -1;
                }
                else if(board[r][c] == 0 && numAliveNeighbors == 3)
                {
                    board[r][c] = 1;
                }
            }
        }
    }

    drawBoard(board);

    free(board);

    return 0;
}