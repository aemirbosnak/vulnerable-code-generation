//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Cell {
    int row;
    int col;
    char status;
} Cell;

Cell **create_board() {
    Cell **board = (Cell **)malloc(BOARD_SIZE * sizeof(Cell *));
    for (int r = 0; r < BOARD_SIZE; r++) {
        board[r] = (Cell *)malloc(BOARD_SIZE * sizeof(Cell));
        for (int c = 0; c < BOARD_SIZE; c++) {
            board[r][c].row = r;
            board[r][c].col = c;
            board[r][c].status = 'N';
        }
    }
    return board;
}

void print_board(Cell **board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            printf("%c ", board[r][c].status);
        }
        printf("\n");
    }
}

int is_board_full(Cell **board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (board[r][c].status == 'N') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    Cell **board = create_board();

    // Play as X
    board[rand() % BOARD_SIZE][rand() % BOARD_SIZE].status = 'X';

    // AI's turn
    int move = rand() % 9;
    board[move / BOARD_SIZE][move % BOARD_SIZE].status = 'O';

    print_board(board);

    if (board[0][0].status == 'O' || board[0][1].status == 'O' || board[0][2].status == 'O' ||
        board[1][0].status == 'O' || board[1][1].status == 'O' || board[1][2].status == 'O' ||
        board[2][0].status == 'O' || board[2][1].status == 'O' || board[2][2].status == 'O') {
        printf("AI won!");
    } else if (is_board_full(board)) {
        printf("It's a draw!");
    } else {
        printf("Game continues...");
    }

    return 0;
}