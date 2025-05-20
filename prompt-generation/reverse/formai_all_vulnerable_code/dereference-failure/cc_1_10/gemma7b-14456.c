//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **board;
    int current_player;
    int game_status;
} Board;

void initialize_board(Board *board) {
    board->board = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(int));
    board->current_player = 1;
    board->game_status = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }
}

int is_board_full(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

void make_move(Board *board, int row, int col) {
    if (board->board[row][col] != 0) {
        return;
    }

    board->board[row][col] = board->current_player;
    board->current_player *= -1;
}

int check_win(Board *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return board->board[0][i] * 2;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
            return board->board[j][0] * 2;
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return board->board[0][0] * 2;
    }

    // If all else fails, it's a draw
    return 0;
}

int main() {
    Board board;
    initialize_board(&board);

    // Game loop
    while (!is_board_full(&board) && check_win(&board) == 0) {
        // Get move from user
        int row, col;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &col);

        // Make move
        make_move(&board, row, col);
    }

    // Game over
    if (check_win(&board) != 0) {
        printf("Winner: Player %d\n", check_win(&board));
    } else {
        printf("Draw!\n");
    }

    return 0;
}