//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Sherlock Holmes
// A Sherlock Holmes-style C Tic Tac Toe AI

#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **board;
    int current_player;
    int game_status;
} Board;

Board* initialize_board() {
    Board* board = malloc(sizeof(Board));
    board->board = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(int));
    board->current_player = 1;
    board->game_status = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }

    return board;
}

void display_board(Board* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board->board[i][j]);
        }
        printf("\n");
    }
}

int check_win(Board* board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return board->board[0][i];
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
            return board->board[j][0];
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return board->board[0][0];
    }

    // If all checks fail, it's a draw
    return 0;
}

void make_move(Board* board, int row, int col) {
    if (board->board[row][col] != 0) {
        return;
    }

    board->board[row][col] = board->current_player;

    if (check_win(board) != 0) {
        board->game_status = 1;
    } else if (board->board[row][col] == board->current_player) {
        board->current_player = (board->current_player == 1) ? 2 : 1;
    }
}

int main() {
    Board* board = initialize_board();

    while (!board->game_status) {
        display_board(board);

        int row, col;
        printf("Enter your move (row, column): ");
        scanf("%d %d", &row, &col);

        make_move(board, row, col);
    }

    display_board(board);

    if (board->game_status == 1) {
        printf("Congratulations! You won!");
    } else {
        printf("It's a draw!");
    }

    return 0;
}