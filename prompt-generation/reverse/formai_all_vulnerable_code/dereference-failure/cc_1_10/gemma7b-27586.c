//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: interoperable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **cells;
    int turn;
    int winner;
} Board;

Board* createBoard() {
    Board* board = malloc(sizeof(Board));
    board->cells = malloc(BOARD_SIZE * sizeof(int*));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->cells[i] = malloc(BOARD_SIZE * sizeof(int));
    }
    board->turn = 0;
    board->winner = -1;
    return board;
}

void placeMove(Board* board, int row, int col) {
    if (board->cells[row][col] != 0) {
        return;
    }
    board->cells[row][col] = board->turn;
    board->turn++;
}

int checkWin(Board* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->cells[0][i] == board->cells[1][i] && board->cells[0][i] == board->cells[2][i] && board->cells[0][i] != 0) {
            return board->cells[0][i];
        }
    }

    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->cells[j][0] == board->cells[j][1] && board->cells[j][0] == board->cells[j][2] && board->cells[j][0] != 0) {
            return board->cells[j][0];
        }
    }

    if (board->cells[0][0] == board->cells[1][1] && board->cells[0][0] == board->cells[2][2] && board->cells[0][0] != 0) {
        return board->cells[0][0];
    }

    return -1;
}

int main() {
    Board* board = createBoard();

    // Game loop
    while (!checkWin(board) && board->turn < BOARD_SIZE * BOARD_SIZE) {
        int row, col;
        printf("Enter row and column (1-3): ");
        scanf("%d %d", &row, &col);
        placeMove(board, row, col);
    }

    // Game over
    if (checkWin(board) != -1) {
        printf("Winner: Player %d\n", checkWin(board));
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}