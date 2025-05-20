//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void drawBoard(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%c ", board[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

void simulateGame(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            int neighbors = 0;
            for (int dr = -1; dr <= 1; dr++)
            {
                for (int dc = -1; dc <= 1; dc++)
                {
                    if (board[r + dr][c + dc] && board[r + dr][c + dc] != 'S')
                    {
                        neighbors++;
                    }
                }
            }
            if (board[r][c] == 'O' && neighbors >= 3)
            {
                board[r][c] = 'T';
            }
            else if (board[r][c] == 'T' && neighbors < 2)
            {
                board[r][c] = 'O';
            }
        }
    }
}

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int r = 0; r < size; r++)
    {
        board[r] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the board
    board[1][1] = board[2][2] = board[2][3] = board[3][2] = 'T';

    // Simulate the game
    simulateGame(board, size);

    // Draw the board
    drawBoard(board, size);

    return 0;
}