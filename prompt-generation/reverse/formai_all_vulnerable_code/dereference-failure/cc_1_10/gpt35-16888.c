//FormAI DATASET v1.0 Category: Chess AI ; Style: beginner-friendly
#include <stdio.h>

/* Board size. Must be an even number. */
#define BOARD_SIZE 8

/* Piece types */
#define EMPTY 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

/* Piece colors */
#define WHITE 0
#define BLACK 1

/* Piece structure */
typedef struct {
    int type;
    int color;
} Piece;

/* Board structure */
typedef struct {
    Piece** pieces;
} Board;

/* Creates a new empty board */
Board* new_board() {
    Board* board = (Board*)malloc(sizeof(Board));
    board->pieces = (Piece**)malloc(BOARD_SIZE * sizeof(Piece*));
    for(int i = 0; i < BOARD_SIZE; i++) {
        board->pieces[i] = (Piece*)malloc(BOARD_SIZE * sizeof(Piece));
        for(int j = 0; j < BOARD_SIZE; j++) {
            board->pieces[i][j].type = EMPTY;
            board->pieces[i][j].color = WHITE;
        }
    }
    return board;
}

/* Frees the memory */
void free_board(Board* board) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        free(board->pieces[i]);
    }
    free(board->pieces);
    free(board);
}

/* Initializes the board with the pieces */
void init_board(Board* board) {
    // Pawns
    for(int i = 0; i < BOARD_SIZE; i++) {
        board->pieces[1][i].type = PAWN;
        board->pieces[1][i].color = BLACK;
        board->pieces[BOARD_SIZE - 2][i].type = PAWN;
        board->pieces[BOARD_SIZE - 2][i].color = WHITE;
    }
    // Knights
    board->pieces[0][1].type = KNIGHT;
    board->pieces[0][1].color = BLACK;
    board->pieces[0][BOARD_SIZE - 2].type = KNIGHT;
    board->pieces[0][BOARD_SIZE - 2].color = BLACK;
    board->pieces[BOARD_SIZE - 1][1].type = KNIGHT;
    board->pieces[BOARD_SIZE - 1][1].color = WHITE;
    board->pieces[BOARD_SIZE - 1][BOARD_SIZE - 2].type = KNIGHT;
    board->pieces[BOARD_SIZE - 1][BOARD_SIZE - 2].color = WHITE;
    // Bishops
    board->pieces[0][2].type = BISHOP;
    board->pieces[0][2].color = BLACK;
    board->pieces[0][BOARD_SIZE - 3].type = BISHOP;
    board->pieces[0][BOARD_SIZE - 3].color = BLACK;
    board->pieces[BOARD_SIZE - 1][2].type = BISHOP;
    board->pieces[BOARD_SIZE - 1][2].color = WHITE;
    board->pieces[BOARD_SIZE - 1][BOARD_SIZE - 3].type = BISHOP;
    board->pieces[BOARD_SIZE - 1][BOARD_SIZE - 3].color = WHITE;
    // Rooks
    board->pieces[0][0].type = ROOK;
    board->pieces[0][0].color = BLACK;
    board->pieces[0][BOARD_SIZE - 1].type = ROOK;
    board->pieces[0][BOARD_SIZE - 1].color = BLACK;
    board->pieces[BOARD_SIZE - 1][0].type = ROOK;
    board->pieces[BOARD_SIZE - 1][0].color = WHITE;
    board->pieces[BOARD_SIZE - 1][BOARD_SIZE - 1].type = ROOK;
    board->pieces[BOARD_SIZE - 1][BOARD_SIZE - 1].color = WHITE;
    // Queens
    board->pieces[0][3].type = QUEEN;
    board->pieces[0][3].color = BLACK;
    board->pieces[BOARD_SIZE - 1][3].type = QUEEN;
    board->pieces[BOARD_SIZE - 1][3].color = WHITE;
    // Kings
    board->pieces[0][4].type = KING;
    board->pieces[0][4].color = BLACK;
    board->pieces[BOARD_SIZE - 1][4].type = KING;
    board->pieces[BOARD_SIZE - 1][4].color = WHITE;
}

/* Prints the board */
void print_board(Board* board) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            Piece p = board->pieces[i][j];
            if(p.type == EMPTY) {
                printf(".");
            } else if(p.type == PAWN) {
                printf(p.color == WHITE ? "P" : "p");
            } else if(p.type == KNIGHT) {
                printf(p.color == WHITE ? "N" : "n");
            } else if(p.type == BISHOP) {
                printf(p.color == WHITE ? "B" : "b");
            } else if(p.type == ROOK) {
                printf(p.color == WHITE ? "R" : "r");
            } else if(p.type == QUEEN) {
                printf(p.color == WHITE ? "Q" : "q");
            } else if(p.type == KING) {
                printf(p.color == WHITE ? "K" : "k");
            }
        }
        printf("\n");
    }
}

int main() {
    Board* board = new_board();
    init_board(board);
    print_board(board);
    free_board(board);
    return 0;
}