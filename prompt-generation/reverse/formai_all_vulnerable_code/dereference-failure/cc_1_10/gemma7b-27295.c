//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: systematic
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **board;
    int turn;
} Board;

Board *create_board() {
    Board *board = malloc(sizeof(Board));
    board->board = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(int));
    board->turn = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }

    return board;
}

void make_move(Board *board, int row, int col) {
    if (board->board[row][col] != 0) {
        return;
    }

    board->board[row][col] = board->turn;
}

int is_won(Board *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return 1;
    }

    // If all cells are occupied and no one has won, it's a draw
    return 2;
}

int main() {
    srand(time(NULL));

    Board *board = create_board();

    // Play until someone wins or it's a draw
    while (1) {
        // Get the player's move
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;

        // Make the move
        make_move(board, row, col);

        // Check if the player has won or it's a draw
        int result = is_won(board);

        // If the player has won, they win
        if (result == 1) {
            printf("Player %d has won!", board->turn);
            break;
        }

        // If it's a draw, it's a draw
        else if (result == 2) {
            printf("It's a draw!");
            break;
        }
    }

    return 0;
}