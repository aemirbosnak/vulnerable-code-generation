//FormAI DATASET v1.0 Category: Table Game ; Style: retro
#include <stdio.h>

// function to display the game board
void display(char board[])
{
    printf("\n\n\t      |      |      ");
    printf("\n\t   %c  |   %c  |   %c  ", board[0], board[1], board[2]);
    printf("\n\t _____|______|_____");
    printf("\n\t      |      |      ");
    printf("\n\t   %c  |   %c  |   %c  ", board[3], board[4], board[5]);
    printf("\n\t _____|______|_____");
    printf("\n\t      |      |      ");
    printf("\n\t   %c  |   %c  |   %c  ", board[6], board[7], board[8]);
    printf("\n\t      |      |      \n\n");
}

// function to check if the entered move is valid or not
int isValidMove(char board[], int move)
{
    if (board[move] == ' ')
        return 1;
    else
        return 0;
}

// function to check if the game is over or not
int isGameOver(char board[], char curr_player)
{
    int i;

    // check if any row is same
    for (i = 0; i < 9; i += 3)
        if (board[i] == curr_player && board[i+1] == curr_player && board[i+2] == curr_player)
            return 1;

    // check if any column is same
    for (i = 0; i < 3; i++)
        if (board[i] == curr_player && board[i+3] == curr_player && board[i+6] == curr_player)
            return 1;

    // check if any diagonal is same
    if ((board[0] == curr_player && board[4] == curr_player && board[8] == curr_player) || (board[2] == curr_player && board[4] == curr_player && board[6] == curr_player))
        return 1;

    // check if the board is full
    for (i = 0; i < 9; i++)
        if (board[i] == ' ')
            return 0;

    // if none of the above conditions are true, return that the game is a tie
    return -1;
}

int main()
{
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int move;
    char curr_player = 'X';
    int result;

    while(1)
    {
        // display the game board
        display(board);

        // take input from the user
        printf("\n%s's turn. Enter your move (1-9): ", (curr_player == 'X') ? "Player 1" : "Player 2");
        scanf("%d", &move);

        // check if the move is valid or not
        if (isValidMove(board, move-1))
            board[move-1] = curr_player;
        else
        {
            printf("\nInvalid move. Try again.\n");
            continue;
        }

        // check if the game is over or not
        result = isGameOver(board, curr_player);

        // if the game is over, display the result
        if (result == 1)
        {
            display(board);
            printf("\n%s wins!\n", (curr_player == 'X') ? "Player 1" : "Player 2");
            break;
        }
        else if (result == -1)
        {
            display(board);
            printf("\nGame is a tie!\n");
            break;
        }

        // switch to the other player
        curr_player = (curr_player == 'X') ? 'O' : 'X';
    }

    return 0;
}