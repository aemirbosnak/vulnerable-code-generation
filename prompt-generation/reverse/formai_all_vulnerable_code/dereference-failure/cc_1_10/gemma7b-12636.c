//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize_board(int **board);
void display_board(int **board);
void make_move(int **board, int player);
int check_win(int **board, int player);
int main()
{
    int **board;
    int player = 1;
    int game_over = 0;

    initialize_board(&board);
    display_board(board);

    while (!game_over)
    {
        make_move(board, player);
        display_board(board);

        if (check_win(board, player) == 1)
        {
            game_over = 1;
            printf("Player %d won!", player);
        }
        else if (check_win(board, player) == 0)
        {
            game_over = 1;
            printf("It's a draw!");
        }
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}

void initialize_board(int **board)
{
    *board = malloc(9 * sizeof(int));
    for (int i = 0; i < 9; i++)
    {
        (*board)[i] = 0;
    }
}

void display_board(int **board)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", (*board)[i * 3 + j]);
        }
        printf("\n");
    }
}

void make_move(int **board, int player)
{
    int move;

    printf("Enter your move (1-9): ");
    scanf("%d", &move);

    if (board[move - 1] == 0)
    {
        board[move - 1] = player;
    }
    else
    {
        printf("Invalid move!");
    }
}

int check_win(int **board, int player)
{
    for (int i = 0; i < 3; i++)
    {
        // Check rows
        if (board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player)
        {
            return 1;
        }

        // Check columns
        if (board[0] == player && board[3] == player && board[6] == player)
        {
            return 1;
        }

        // Check diagonals
        if (board[2] == player && board[4] == player && board[8] == player)
        {
            return 1;
        }
    }

    return 0;
}