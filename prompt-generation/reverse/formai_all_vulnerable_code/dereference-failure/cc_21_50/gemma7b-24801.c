//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array of characters
    char **board = (char **)malloc(5 * sizeof(char *));
    for (int i = 0; i < 5; i++)
    {
        board[i] = (char *)malloc(5 * sizeof(char));
    }

    // Initialize the board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = ' ';
        }
    }

    // Place the player's piece in a random position
    board[rand() % 5][rand() % 5] = 'X';

    // Display the board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Check if the player has won
    if (board[0][0] == 'X' || board[0][1] == 'X' || board[0][2] == 'X' ||
        board[1][0] == 'X' || board[1][1] == 'X' || board[1][2] == 'X' ||
        board[2][0] == 'X' || board[2][1] == 'X' || board[2][2] == 'X' ||
        board[3][0] == 'X' || board[3][1] == 'X' || board[3][2] == 'X' ||
        board[4][0] == 'X' || board[4][1] == 'X' || board[4][2] == 'X')
    {
        printf("You have won!\n");
    }
    else
    {
        printf("It's a draw.\n");
    }

    // Free the memory allocated for the board
    for (int i = 0; i < 5; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}