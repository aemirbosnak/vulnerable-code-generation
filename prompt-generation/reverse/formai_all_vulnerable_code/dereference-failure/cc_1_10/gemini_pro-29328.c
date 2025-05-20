//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Position;

typedef enum {
    EMPTY, BLACK, WHITE
} Piece;

typedef struct {
    Piece **board;
    int size;
} Board;

Board *init_board(int size) {
    Board *board = malloc(sizeof(Board));
    board->board = malloc(sizeof(Piece *) * size);
    for (int i = 0; i < size; i++) {
        board->board[i] = malloc(sizeof(Piece) * size);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board->board[i][j] = EMPTY;
        }
    }

    board->size = size;

    return board;
}

void free_board(Board *board) {
    for (int i = 0; i < board->size; i++) {
        free(board->board[i]);
    }

    free(board->board);
    free(board);
}

void print_board(Board *board) {
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            switch (board->board[i][j]) {
            case EMPTY:
                printf(" ");
                break;
            case BLACK:
                printf("B");
                break;
            case WHITE:
                printf("W");
                break;
            }
        }

        printf("\n");
    }
}

int main() {
    Board *board = init_board(8);

    // Place the pieces on the board
    for (int i = 0; i < 3; i++) {
        for (int j = i % 2; j < board->size; j += 2) {
            board->board[i][j] = BLACK;
        }
    }

    for (int i = 5; i < board->size; i++) {
        for (int j = i % 2; j < board->size; j += 2) {
            board->board[i][j] = WHITE;
        }
    }

    // Print the board
    print_board(board);

    // Free the board
    free_board(board);

    return 0;
}