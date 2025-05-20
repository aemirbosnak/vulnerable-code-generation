//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **cells;
    int current_player;
} Board;

void init_board(Board *board) {
    board->cells = malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->cells[i] = malloc(BOARD_SIZE * sizeof(int));
    }
    board->current_player = 1;
}

void place_mark(Board *board, int row, int col) {
    if (board->cells[row][col] != 0) {
        return;
    }
    board->cells[row][col] = board->current_player;
    board->current_player *= -1;
}

int check_win(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->cells[0][i] == board->cells[1][i] && board->cells[0][i] == board->cells[2][i] && board->cells[0][i] != 0) {
            return 1;
        }
    }

    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->cells[j][0] == board->cells[j][1] && board->cells[j][0] == board->cells[j][2] && board->cells[j][0] != 0) {
            return 1;
        }
    }

    if (board->cells[0][0] == board->cells[1][1] && board->cells[0][0] == board->cells[2][2] && board->cells[0][0] != 0) {
        return 1;
    }

    return 0;
}

int main() {
    Board board;
    init_board(&board);

    // Play the game
    place_mark(&board, 0, 0);
    place_mark(&board, 1, 1);
    place_mark(&board, 0, 1);
    place_mark(&board, 2, 0);

    // Check if anyone won
    if (check_win(&board)) {
        printf("Winner!");
    } else {
        printf("It's a draw!");
    }

    return 0;
}