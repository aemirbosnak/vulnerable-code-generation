//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Donald Knuth
#include <stdlib.h>
#include <time.h>

#define MAX_BOARD_SIZE 3

typedef struct Board {
    int **board;
    int size;
    int turn;
} Board;

Board *initBoard(int size) {
    Board *board = malloc(sizeof(Board));
    board->size = size;
    board->board = malloc(size * size * sizeof(int));
    board->turn = 0;
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            board->board[r][c] = 0;
        }
    }
    return board;
}

void playMove(Board *board, int row, int col) {
    if (board->board[row][col] != 0) {
        return;
    }
    board->board[row][col] = board->turn;
    board->turn ^= 1;
}

int isWon(Board *board) {
    for (int r = 0; r < board->size; r++) {
        if (board->board[r][0] == board->board[r][1] && board->board[r][0] == board->board[r][2] && board->board[r][0] != 0) {
            return 1;
        }
    }
    for (int c = 0; c < board->size; c++) {
        if (board->board[0][c] == board->board[1][c] && board->board[0][c] == board->board[2][c] && board->board[0][c] != 0) {
            return 1;
        }
    }
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return 1;
    }
    return 0;
}

void freeBoard(Board *board) {
    free(board->board);
    free(board);
}

int main() {
    srand(time(NULL));
    int size = MAX_BOARD_SIZE;
    Board *board = initBoard(size);

    playMove(board, rand() % size, rand() % size);
    playMove(board, rand() % size, rand() % size);

    if (isWon(board)) {
        printf("Player %d won!", board->turn);
    } else {
        printf("It's a draw!");
    }

    freeBoard(board);
    return 0;
}