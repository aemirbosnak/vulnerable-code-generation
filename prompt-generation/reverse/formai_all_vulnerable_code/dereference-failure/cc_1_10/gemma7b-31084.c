//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void drawBoard(int **board)
{
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            printf("%c ", board[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

int calculateAlive(int **board, int r, int c)
{
    int alive = 0;

    // Check the 8 neighboring cells
    for(int dr = -1; dr <= 1; dr++)
    {
        for(int dc = -1; dc <= 1; dc++)
        {
            if(r + dr >= 0 && r + dr < MAX && c + dc >= 0 && c + dc < MAX && board[r + dr][c + dc])
            {
                alive++;
            }
        }
    }

    return alive;
}

void updateBoard(int **board)
{
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            int alive = calculateAlive(board, r, c);

            if(alive < 2)
            {
                board[r][c] = 0;
            }
            else if(alive == 2)
            {
                board[r][c] = 1;
            }
        }
    }
}

int main()
{
    int **board = (int **)malloc(MAX * sizeof(int *));
    for(int i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Initialize the board
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            board[r][c] = 0;
        }
    }

    // Seed the board with some life
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;

    // Simulate the game for 10 generations
    for(int gen = 0; gen < 10; gen++)
    {
        updateBoard(board);
        drawBoard(board);
    }

    free(board);

    return 0;
}