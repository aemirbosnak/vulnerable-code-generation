//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int row;
    int col;
    int value;
    int is_white;
} Piece;

typedef struct {
    int size;
    Piece* pieces;
} Board;

Board* create_board(int size) {
    Board* board = (Board*) malloc(sizeof(Board));
    board->size = size;
    board->pieces = (Piece*) malloc(size * size * sizeof(Piece));
    return board;
}

void free_board(Board* board) {
    free(board->pieces);
    free(board);
}

void print_board(Board* board) {
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            printf("%d ", board->pieces[i * board->size + j].value);
        }
        printf("\n");
    }
}

void initialize_board(Board* board, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int random_value = rand() % 2 + 1;
            board->pieces[i * size + j].value = random_value;
            board->pieces[i * size + j].is_white = random_value % 2;
        }
    }
}

int main() {
    int size = 8;
    Board* board = create_board(size);
    initialize_board(board, size);
    print_board(board);
    free_board(board);
    return 0;
}