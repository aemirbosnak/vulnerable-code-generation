//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1, turn = 0, win = 0, i, j;

    // Seed the random number generator
    srand(time(NULL));

    // Game loop
    while (!win && turn < 9)
    {
        // Get the player's move
        printf("Enter your move (1-9): ");
        int move = atoi(gets());

        // Validate the move
        if (move < 1 || move > 9)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place the piece on the board
        board[move / 3][move % 3] = player;

        // Check if the player has won
        win = checkWin(board, player);

        // If the player has not won, it is the next turn
        if (!win)
        {
            turn++;

            // Make the AI's move
            move = aiMove(board);

            // Place the AI's piece on the board
            board[move / 3][move % 3] = player;
        }
    }

    // Game over
    if (win)
    {
        printf("You won! Congratulations!\n");
    }
    else
    {
        printf("It's a draw. Try again next time.\n");
    }

    return 0;
}

int checkWin(int **board, int player)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player)
    {
        return 1;
    }

    // No win
    return 0;
}

int aiMove(int **board)
{
    // Get a random move
    int move = rand() % 9;

    // If the move is valid, return it
    if (board[move / 3][move % 3] == 0)
    {
        return move;
    }

    // Otherwise, try again
    else
    {
        return aiMove(board);
    }
}