//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: multivariable
#include <stdlib.h>
#include <stdio.h>

#define MAX_BOARD_SIZE 3

typedef struct Board {
    int **board;
    int current_player;
    int game_status;
} Board;

void initialize_board(Board *board) {
    board->board = malloc(MAX_BOARD_SIZE * MAX_BOARD_SIZE * sizeof(int));
    board->current_player = 1;
    board->game_status = 0;

    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }
}

int get_available_move(Board *board) {
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            if (board->board[i][j] == 0) {
                return i * MAX_BOARD_SIZE + j;
            }
        }
    }

    return -1;
}

void make_move(Board *board, int move) {
    int row = move / MAX_BOARD_SIZE;
    int col = move % MAX_BOARD_SIZE;

    board->board[row][col] = board->current_player;
}

int check_win(Board *board) {
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return board->board[0][i];
        }
    }

    for (int j = 0; j < MAX_BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
            return board->board[j][0];
        }
    }

    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return board->board[0][0];
    }

    return 0;
}

int main() {
    Board board;
    initialize_board(&board);

    // Play the game
    while (!check_win(&board) && get_available_move(&board) != -1) {
        make_move(&board, get_available_move(&board));
    }

    // Print the winner or draw
    if (check_win(&board) != 0) {
        printf("Player %d won!", check_win(&board));
    } else {
        printf("It's a draw!");
    }

    return 0;
}