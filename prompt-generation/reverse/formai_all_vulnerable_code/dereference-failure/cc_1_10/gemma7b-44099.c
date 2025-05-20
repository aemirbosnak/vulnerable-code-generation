//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10

void draw_board(int **board);
void make_move(int **board, int player);
int check_win(int **board, int player);

int main()
{
    int **board = NULL;
    int player = 1;
    int game_over = 0;

    board = (int **)malloc(MAX_NUM * MAX_NUM * sizeof(int));
    for (int i = 0; i < MAX_NUM; i++)
    {
        board[i] = (int *)malloc(MAX_NUM * sizeof(int));
        for (int j = 0; j < MAX_NUM; j++)
        {
            board[i][j] = 0;
        }
    }

    draw_board(board);

    while (!game_over)
    {
        make_move(board, player);
        draw_board(board);

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
        else
        {
            player = (player == 1) ? 2 : 1;
        }
    }

    free(board);

    return 0;
}

void draw_board(int **board)
{
    for (int i = 0; i < MAX_NUM; i++)
    {
        for (int j = 0; j < MAX_NUM; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void make_move(int **board, int player)
{
    int row, column;

    printf("Enter row (1-10): ");
    scanf("%d", &row);

    printf("Enter column (1-10): ");
    scanf("%d", &column);

    if (board[row - 1][column - 1] == 0)
    {
        board[row - 1][column - 1] = player;
    }
    else
    {
        printf("Move not valid!\n");
    }
}

int check_win(int **board, int player)
{
    // Check rows
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < MAX_NUM; j++)
    {
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] == player)
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