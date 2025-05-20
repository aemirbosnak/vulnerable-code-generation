//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board
{
    int **grid;
    int current_player;
    int game_status;
} Board;

void initialize_board(Board *board)
{
    board->grid = (int **)malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board->grid[i] = (int *)malloc(BOARD_SIZE * sizeof(int));
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board->grid[i][j] = 0;
        }
    }

    board->current_player = 1;
    board->game_status = 0;
}

void place_mark(Board *board, int x, int y)
{
    if (board->grid[x][y] != 0)
    {
        return;
    }

    board->grid[x][y] = board->current_player;
}

int check_win(Board *board, int player)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board->grid[0][i] == player && board->grid[1][i] == player && board->grid[2][i] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board->grid[j][0] == player && board->grid[j][1] == player && board->grid[j][2] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board->grid[0][0] == player && board->grid[1][1] == player && board->grid[2][2] == player)
    {
        return 1;
    }

    if (board->grid[0][2] == player && board->grid[1][1] == player && board->grid[2][0] == player)
    {
        return 1;
    }

    return 0;
}

void play_game(Board *board)
{
    int game_round = 0;
    while (board->game_status == 0)
    {
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        place_mark(board, x, y);

        if (check_win(board, board->current_player) == 1)
        {
            board->game_status = 1;
            printf("You won!");
        }
        else
        {
            board->current_player = -board->current_player;
        }

        game_round++;
    }

    if (board->game_status == 0)
    {
        printf("It's a draw!");
    }
}

int main()
{
    Board board;
    initialize_board(&board);
    play_game(&board);

    return 0;
}