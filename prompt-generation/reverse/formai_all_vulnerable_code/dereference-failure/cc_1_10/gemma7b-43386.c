//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z;
    char **board = NULL;

    // Allocate memory for the board
    board = (char **)malloc(5 * sizeof(char *) + 1);
    for (x = 0; x < 5; x++)
    {
        board[x] = (char *)malloc(5 * sizeof(char) + 1);
    }

    // Initialize the board
    for (x = 0; x < 5; x++)
    {
        for (y = 0; y < 5; y++)
        {
            board[x][y] = ' ';
        }
    }

    // Game loop
    while (1)
    {
        // Get the player's move
        printf("Enter your move (x, y): ");
        scanf("%d, %d", &x, &y);

        // Check if the move is valid
        if (x < 0 || x >= 5 || y < 0 || y >= 5)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Check if the move is already made
        if (board[x][y] != ' ')
        {
            printf("Move already made.\n");
            continue;
        }

        // Make the move
        board[x][y] = 'X';

        // Print the board
        for (x = 0; x < 5; x++)
        {
            for (y = 0; y < 5; y++)
            {
                printf("%c ", board[x][y]);
            }
            printf("\n");
        }

        // Check if the player has won
        if (checkWin(board, x, y) == 1)
        {
            printf("You win!\n");
            break;
        }

        // Check if the board is full
        if (isFull(board) == 1)
        {
            printf("Draw.\n");
            break;
        }
    }

    // Free the memory
    for (x = 0; x < 5; x++)
    {
        free(board[x]);
    }
    free(board);

    return 0;
}

int checkWin(char **board, int x, int y)
{
    // Check rows
    for (int i = 0; i < 5; i++)
    {
        if (board[x][i] == board[x][y] && board[x][i] != ' ')
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 5; j++)
    {
        if (board[j][y] == board[x][y] && board[j][y] != ' ')
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[x][y] && board[0][0] != ' ')
    {
        return 1;
    }
    if (board[4][0] == board[x][y] && board[4][0] != ' ')
    {
        return 1;
    }

    return 0;
}

int isFull(char **board)
{
    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            if (board[x][y] == ' ')
            {
                return 0;
            }
        }
    }

    return 1;
}