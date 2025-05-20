//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LIVES 3

int main()
{
    int lives = MAX_LIVES;
    int score = 0;
    char board[3][3] = {{0, 0, 0},
                              {0, 0, 0},
                              {0, 0, 0}};

    // Seed the random number generator
    srand(time(NULL));

    // Game loop
    while (lives > 0)
    {
        // Display the game board
        printf("Board:\n");
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                printf("%c ", board[r][c]);
            }
            printf("\n");
        }

        // Get the player's move
        int move = rand() % 9;

        // Check if the move is valid
        if (board[move / 3][move % 3] == 0)
        {
            // Make the move
            board[move / 3][move % 3] = 'X';

            // Check if the player has won
            if (checkWin(board) == 1)
            {
                printf("You win!\n");
                score++;
                lives = MAX_LIVES;
            }
            else
            {
                // decrement lives
                lives--;
                printf("Sorry, that move was not valid.\n");
            }
        }
        else
        {
            printf("Sorry, that move was not valid.\n");
        }
    }

    // Game over
    printf("Game over. Your score is: %d\n", score);

    return 0;
}

int checkWin(char **board)
{
    // Check rows
    for (int r = 0; r < 3; r++)
    {
        if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] != 0)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < 3; c++)
    {
        if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] != 0)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0)
    {
        return 1;
    }

    // No winner
    return 0;
}