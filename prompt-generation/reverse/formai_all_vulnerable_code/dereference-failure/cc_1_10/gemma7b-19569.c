//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board
{
    int **board;
    int current_player;
    int game_status;
} Board;

Board* initialize_board()
{
    Board* board = malloc(sizeof(Board));
    board->board = malloc(sizeof(int *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board->board[i] = malloc(sizeof(int) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board->board[i][j] = 0;
        }
    }

    board->current_player = 1;
    board->game_status = 0;

    return board;
}

void place_mark(Board* board, int row, int col)
{
    if (board->board[row][col] != 0)
    {
        return;
    }

    board->board[row][col] = board->current_player;
    board->current_player *= -1;
}

int check_win(Board* board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0)
        {
            return board->board[0][i] * 2;
        }
    }

    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0)
        {
            return board->board[j][0] * 2;
        }
    }

    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0)
    {
        return board->board[0][0] * 2;
    }

    return 0;
}

int main()
{
    Board* board = initialize_board();

    while (!board->game_status)
    {
        int row, col;
        printf("Enter row and column (1-3): ");
        scanf("%d %d", &row, &col);

        place_mark(board, row, col);

        if (check_win(board) != 0)
        {
            board->game_status = 1;
            printf("Winner: Player %d!\n", check_win(board));
        }
    }

    return 0;
}