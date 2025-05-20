//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Dynamic memory allocation for the game board
    int **board = NULL;
    int size = 5;
    board = (int **)malloc(size * size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the game board
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = 0;
        }
    }

    // Game loop
    while (1)
    {
        // Get the player's move
        int row, column;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &column);

        // Check if the move is valid
        if (board[row][column] != 0)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Mark the move as played
        board[row][column] = 1;

        // Check if the player has won
        if (checkWin(board, size, row, column))
        {
            printf("You win!\n");
            break;
        }

        // If there is no winner, continue the game
        else
        {
            printf("No winner yet.\n");
        }
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < size; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}

int checkWin(int **board, int size, int row, int column)
{
    // Check rows
    for (int i = 0; i < size; i++)
    {
        if (board[row][i] == board[row][column] && board[row][i] != 0)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < size; j++)
    {
        if (board[j][column] == board[row][column] && board[j][column] != 0)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[row - 1][column - 1] == board[row][column] && board[row - 1][column - 1] != 0)
    {
        return 1;
    }
    if (board[row + 1][column + 1] == board[row][column] && board[row + 1][column + 1] != 0)
    {
        return 1;
    }

    // No winner
    return 0;
}