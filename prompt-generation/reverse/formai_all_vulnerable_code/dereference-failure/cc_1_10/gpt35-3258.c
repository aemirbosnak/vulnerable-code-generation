//FormAI DATASET v1.0 Category: Chess engine ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef enum {
    WHITE = 0,
    BLACK = 1
} Player;

typedef enum {
    PAWN = 'p',
    KNIGHT = 'n',
    BISHOP = 'b',
    ROOK = 'r',
    QUEEN = 'q',
    KING = 'k',
    EMPTY = '-'
} Piece;

typedef struct {
    Piece piece_type;
    Player player;
} ChessPiece;

typedef struct {
    ChessPiece *pieces[BOARD_SIZE][BOARD_SIZE];
} ChessBoard;

void print_board(ChessBoard *board) {
    printf("\n\n  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'a' + i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->pieces[i][j] == NULL) {
                printf("%c ", EMPTY);
            } else {
                printf("%c ", board->pieces[i][j]->piece_type);
            }
        }
        printf("%d\n", BOARD_SIZE - i);
    }
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'a' + i);
    }
    printf("\n");
}

void initialize_board(ChessBoard *board) {
    ChessPiece *piece;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 0 || i == BOARD_SIZE - 1) {
                if (j == 0 || j == BOARD_SIZE - 1) {
                    piece = (ChessPiece *) malloc(sizeof(ChessPiece));
                    piece->piece_type = ROOK;
                    piece->player = i == 0 ? WHITE : BLACK;
                    board->pieces[i][j] = piece;
                } else if (j == 1 || j == BOARD_SIZE - 2) {
                    piece = (ChessPiece *) malloc(sizeof(ChessPiece));
                    piece->piece_type = KNIGHT;
                    piece->player = i == 0 ? WHITE : BLACK;
                    board->pieces[i][j] = piece;
                } else if (j == 2 || j == BOARD_SIZE - 3) {
                    piece = (ChessPiece *) malloc(sizeof(ChessPiece));
                    piece->piece_type = BISHOP;
                    piece->player = i == 0 ? WHITE : BLACK;
                    board->pieces[i][j] = piece;
                } else if (j == 3) {
                    piece = (ChessPiece *) malloc(sizeof(ChessPiece));
                    piece->piece_type = QUEEN;
                    piece->player = i == 0 ? WHITE : BLACK;
                    board->pieces[i][j] = piece;
                } else if (j == 4) {
                    piece = (ChessPiece *) malloc(sizeof(ChessPiece));
                    piece->piece_type = KING;
                    piece->player = i == 0 ? WHITE : BLACK;
                    board->pieces[i][j] = piece;
                }
            } else if (i == 1 || i == BOARD_SIZE - 2) {
                piece = (ChessPiece *) malloc(sizeof(ChessPiece));
                piece->piece_type = PAWN;
                piece->player = i == 1 ? WHITE : BLACK;
                board->pieces[i][j] = piece;
            } else {
                board->pieces[i][j] = NULL;
            }
        }
    }
}

int main(void) {
    ChessBoard board;
    initialize_board(&board);
    print_board(&board);
    return 0;
}