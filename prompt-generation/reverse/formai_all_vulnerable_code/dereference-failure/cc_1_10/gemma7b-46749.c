//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 25

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

void updateBoard(int **board)
{
    for(int r = 0; r < MAX_SIZE; r++)
    {
        for(int c = 0; c < MAX_SIZE; c++)
        {
            int aliveNeighbors = 0;
            for(int dr = -1; dr <= 1; dr++)
            {
                for(int dc = -1; dc <= 1; dc++)
                {
                    if(board[r + dr][c + dc] && board[r + dr][c + dc] != 'O')
                    {
                        aliveNeighbors++;
                    }
                }
            }
            if(aliveNeighbors < 2)
            {
                board[r][c] = ' ';
            }
            else if(aliveNeighbors == 2)
            {
                board[r][c] = 'O';
            }
        }
    }
}

int main()
{
    int **board = (int**)malloc(MAX_SIZE * sizeof(int*));
    for(int i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int*)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    for(int r = 0; r < MAX_SIZE; r++)
    {
        for(int c = 0; c < MAX_SIZE; c++)
        {
            board[r][c] = ' ';
        }
    }

    board[1][1] = 'O';
    board[2][2] = 'O';
    board[2][3] = 'O';

    // Simulate the game for 10 generations
    for(int gen = 0; gen < 10; gen++)
    {
        updateBoard(board);
        drawBoard(board);
    }

    // Free the memory
    for(int i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}