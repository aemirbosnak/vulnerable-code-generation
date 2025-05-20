//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: random
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **cells;
    int current_player;
    int game_status;
} Board;

void initialize_board(Board *board) {
    board->cells = (int **)malloc(sizeof(int *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->cells[i] = (int *)malloc(sizeof(int) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->cells[i][j] = 0;
        }
    }

    board->current_player = 1;
    board->game_status = 0;
}

int get_available_move(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->cells[i][j] == 0) {
                return i * BOARD_SIZE + j;
            }
        }
    }

    return -1;
}

void make_move(Board *board, int move) {
    int row = move / BOARD_SIZE;
    int col = move % BOARD_SIZE;

    board->cells[row][col] = board->current_player;
}

int check_win(Board *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->cells[0][i] == board->cells[1][i] && board->cells[0][i] == board->cells[2][i] && board->cells[0][i] != 0) {
            return board->cells[0][i];
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->cells[j][0] == board->cells[j][1] && board->cells[j][0] == board->cells[j][2] && board->cells[j][0] != 0) {
            return board->cells[j][0];
        }
    }

    // Check diagonals
    if (board->cells[0][0] == board->cells[1][1] && board->cells[0][0] == board->cells[2][2] && board->cells[0][0] != 0) {
        return board->cells[0][0];
    }

    // If all cells are occupied and no one has won, it's a draw
    return -1;
}

int main() {
    Board board;
    initialize_board(&board);

    // Play the game
    while (!check_win(&board) && get_available_move(&board) != -1) {
        make_move(&board, get_available_move(&board));
    }

    // Print the winner or draw
    if (check_win(&board) != -1) {
        printf("Player %d won!", check_win(&board));
    } else {
        printf("It's a draw!");
    }

    return 0;
}