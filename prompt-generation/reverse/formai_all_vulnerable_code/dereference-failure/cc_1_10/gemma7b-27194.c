//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

void drawBoard(int **board, int size)
{
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            printf("%c ", board[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for(int r = 0; r < size; r++)
    {
        board[r] = (int *)malloc(size * sizeof(int));
    }

    // Initial game board
    board[2][2] = 1;
    board[2][3] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

    int generations = 0;
    int alive = 1;

    // Game loop
    while(alive)
    {
        drawBoard(board, size);

        // Calculate next generation
        int **nextBoard = (int **)malloc(size * sizeof(int *));
        for(int r = 0; r < size; r++)
        {
            nextBoard[r] = (int *)malloc(size * sizeof(int));
        }

        for(int r = 0; r < size; r++)
        {
            for(int c = 0; c < size; c++)
            {
                int neighbors = 0;
                if(board[r-1][c] == 1) neighbors++;
                if(board[r+1][c] == 1) neighbors++;
                if(board[r][c-1] == 1) neighbors++;
                if(board[r][c+1] == 1) neighbors++;

                nextBoard[r][c] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            }
        }

        free(board);
        board = nextBoard;
        generations++;

        // Check if game is over
        alive = 0;
        for(int r = 0; r < size; r++)
        {
            for(int c = 0; c < size; c++)
            {
                if(board[r][c] == 1) alive = 1;
            }
        }

        // Print number of generations
        printf("Number of generations: %d\n", generations);
    }

    return 0;
}