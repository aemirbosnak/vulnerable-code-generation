//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void game_setup(int **board, int size);
int move_piece(int **board, int size, int player);
int check_win(int **board, int size, int player);

int main()
{
    int size = 5;
    int **board = NULL;
    int player = 1;

    game_setup(&board, size);
    move_piece(board, size, player);
    check_win(board, size, player);

    return 0;
}

void game_setup(int **board, int size)
{
    *board = (int *)malloc(size * size * sizeof(int));
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            board[r][c] = 0;
        }
    }
}

int move_piece(int **board, int size, int player)
{
    int row, column;

    printf("Enter the row (1-4): ");
    scanf("%d", &row);

    printf("Enter the column (1-4): ");
    scanf("%d", &column);

    if (board[row - 1][column - 1] != 0)
    {
        printf("That position is already taken.\n");
        return -1;
    }

    board[row - 1][column - 1] = player;

    return 0;
}

int check_win(int **board, int size, int player)
{
    // Check rows
    for (int r = 0; r < size; r++)
    {
        if (board[r][0] == player && board[r][1] == player && board[r][2] == player && board[r][3] == player && board[r][4] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < size; c++)
    {
        if (board[0][c] == player && board[1][c] == player && board[2][c] == player && board[3][c] == player && board[4][c] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player && board[3][3] == player && board[4][4] == player)
    {
        return 1;
    }

    // If all moves have been made and there is no winner, it's a draw
    return 0;
}