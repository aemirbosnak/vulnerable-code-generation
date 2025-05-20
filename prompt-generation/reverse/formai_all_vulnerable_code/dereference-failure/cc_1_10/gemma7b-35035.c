//Gemma-7B DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 7

typedef struct Cell {
    int x, y;
    char state;
} Cell;

void initializeBoard(Cell **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (Cell *)malloc(sizeof(Cell));
        board[i]->x = i;
        board[i]->y = -1;
        board[i]->state = 'o';
    }
}

void placePiece(Cell **board, int x, char piece) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i]->x == x && board[i]->y == -1) {
            board[i]->state = piece;
            board[i]->y = 0;
            return;
        }
    }

    printf("Error: Piece placement failed.\n");
}

int checkWin(Cell **board, char piece) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i]->state == piece && board[i+1]->state == piece && board[i+2]->state == piece) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j]->state == piece && board[j+1]->state == piece && board[j+2]->state == piece) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0]->state == piece && board[4]->state == piece && board[8]->state == piece) {
        return 1;
    }

    // No win
    return 0;
}

int main() {
    Cell **board = (Cell **)malloc(sizeof(Cell *) * BOARD_SIZE);
    initializeBoard(board);

    placePiece(board, 0, 'x');
    placePiece(board, 2, 'o');
    placePiece(board, 3, 'x');
    placePiece(board, 4, 'o');
    placePiece(board, 5, 'x');

    if (checkWin(board, 'x') == 1) {
        printf("Player X won!\n");
    } else if (checkWin(board, 'o') == 1) {
        printf("Player O won!\n");
    } else {
        printf("It's a draw.\n");
    }

    return 0;
}