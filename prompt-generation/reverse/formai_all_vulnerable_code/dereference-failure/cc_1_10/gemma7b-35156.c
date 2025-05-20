//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void playGame(int **board, int size)
{
    int i, j, move = 0, winner = 0;

    // Initialize the board
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            board[i][j] = 0;
        }
    }

    // Game loop
    while (!winner && move < MAX_SIZE)
    {
        // Get the player's move
        printf("Enter your move (row, column): ");
        scanf("%d %d", &i, &j);

        // Validate the move
        if (board[i][j] != 0 || i < 0 || i >= size || j < 0 || j >= size)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        board[i][j] = 1;

        // Check if the player won
        winner = checkWin(board, size);

        // Increment the move count
        move++;
    }

    // End the game
    if (winner)
    {
        printf("You won!");
    }
    else
    {
        printf("Draw!");
    }
}

int checkWin(int **board, int size)
{
    int i, j, win = 0;

    // Check rows
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (board[i][j] == board[i][j + 1] && board[i][j] != 0)
            {
                win = 1;
            }
        }
    }

    // Check columns
    for (j = 0; j < size; j++)
    {
        for (i = 0; i < size - 1; i++)
        {
            if (board[i][j] == board[i + 1][j] && board[i][j] != 0)
            {
                win = 1;
            }
        }
    }

    // Check diagonals
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (board[i][j] == board[i + 1][j + 1] && board[i][j] != 0)
            {
                win = 1;
            }
        }
    }

    return win;
}

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
    }

    playGame(board, size);

    return 0;
}