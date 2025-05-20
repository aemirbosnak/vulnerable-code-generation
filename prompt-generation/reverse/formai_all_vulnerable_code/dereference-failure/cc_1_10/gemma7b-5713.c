//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int board[3][3] = {{0, 0, 0},
                              {0, 0, 0},
                              {0, 0, 0}};

    int player = 1;
    int move = 0;

    // Game loop
    while (move < 9)
    {
        // Get the player's move
        int row, column;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &column);

        // Validate the move
        if (board[row][column] != 0)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        board[row][column] = player;

        // Check if the player has won
        if (checkWin(board, player))
        {
            printf("Congratulations, %d! You have won!\n", player);
            break;
        }

        // If there is no winner, switch to the next player
        player = (player == 1) ? 2 : 1;

        // Increment the move counter
        move++;
    }

    // If the game ends in a draw
    if (move == 9)
    {
        printf("It's a draw!\n");
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

    // No winner
    return 0;
}