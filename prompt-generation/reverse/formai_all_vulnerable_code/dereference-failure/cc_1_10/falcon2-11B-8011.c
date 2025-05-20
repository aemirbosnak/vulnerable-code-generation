//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Piece {
    int x, y;
    bool color;
} Piece;

typedef struct Board {
    Piece** pieces;
    int size, direction;
} Board;

Board* new_board(int size, int direction) {
    Board* board = malloc(sizeof(Board));
    board->size = size;
    board->direction = direction;
    board->pieces = malloc(sizeof(Piece*) * size * size);
    for (int i = 0; i < size; i++) {
        board->pieces[i * size] = malloc(sizeof(Piece) * size);
    }
    return board;
}

void free_board(Board* board) {
    for (int i = 0; i < board->size; i++) {
        free(board->pieces[i]);
    }
    free(board->pieces);
    free(board);
}

void print_board(Board* board) {
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            printf("%c ", (board->pieces[i][j].color? 'X' : 'O'));
        }
        printf("\n");
    }
}

void move_piece(Board* board, int x, int y, int dx, int dy, bool color) {
    Piece* piece = &board->pieces[x][y];
    if (piece->color!= color) {
        return;
    }
    if (piece->x + dx < 0 || piece->x + dx >= board->size ||
        piece->y + dy < 0 || piece->y + dy >= board->size) {
        return;
    }
    Piece* new_piece = &board->pieces[piece->x + dx][piece->y + dy];
    new_piece->x = piece->x + dx;
    new_piece->y = piece->y + dy;
    new_piece->color = color;
    Piece* old_piece = &board->pieces[piece->x][piece->y];
    old_piece->color =!color;
}

int main() {
    Board* board = new_board(8, 1);
    int x, y;
    while (true) {
        printf("Enter x, y coordinates: ");
        scanf("%d,%d", &x, &y);
        if (x < 0 || x >= board->size || y < 0 || y >= board->size) {
            printf("Invalid coordinates.\n");
            continue;
        }
        Piece* piece = &board->pieces[x][y];
        if (piece->color == 0) {
            printf("Enter color (1 or -1): ");
            char color;
            scanf("%c", &color);
            if (color == '1' || color == '-1') {
                move_piece(board, x, y, 1, 0, color == '1');
                printf("Move successful.\n");
            } else {
                printf("Invalid color.\n");
            }
        } else {
            printf("Piece already taken.\n");
        }
    }
    free_board(board);
    return 0;
}