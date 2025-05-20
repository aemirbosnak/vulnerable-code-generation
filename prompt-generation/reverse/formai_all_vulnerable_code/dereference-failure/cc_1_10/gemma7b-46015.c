//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: minimalist
#include <stdio.h>

int main()
{
    // Game variables
    int score = 0;
    int lives = 3;
    char board[4][4] = {{0, 0, 0, 0},
                              {0, 0, 0, 0},
                              {0, 0, 0, 0},
                              {0, 0, 0, 0}};

    // Game loop
    while (lives > 0)
    {
        // Display the game board
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < 4; c++)
            {
                printf("%c ", board[r][c]);
            }
            printf("\n");
        }

        // Get the user's move
        int move = 0;
        printf("Enter your move (1-16): ");
        scanf("%d", &move);

        // Validate the move
        if (move < 1 || move > 16)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the user's move on the board
        board[move / 4][move % 4] = 'X';

        // Check if the user has won or lost
        if (checkWin(board) || checkLoss(board))
        {
            // End the game
            break;
        }

        // Increment the score
        score++;
    }

    // Game over
    printf("Game over. Your score is: %d", score);

    return 0;
}

// Function to check if the user has won
int checkWin(char **board)
{
    // Check rows
    for (int r = 0; r < 4; r++)
    {
        if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] == board[r][3] && board[r][0] != 0)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < 4; c++)
    {
        if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] == board[3][c] && board[0][c] != 0)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3] && board[0][0] != 0)
    {
        return 1;
    }

    // No win
    return 0;
}

// Function to check if the user has lost
int checkLoss(char **board)
{
    // Check if the board is full
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            if (board[r][c] == 0)
            {
                return 0;
            }
        }
    }

    // No moves left and no win
    return 1;
}