//FormAI DATASET v1.0 Category: Chess AI ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define Chess Board size
#define BOARD_SIZE 8

// Define Chess Piece score values
#define PAWN_VALUE 1
#define KNIGHT_VALUE 3
#define BISHOP_VALUE 3
#define ROOK_VALUE 5
#define QUEEN_VALUE 9
#define KING_VALUE 0

// Define Chess Piece types
#define EMPTY 0
#define PAWN 'P'
#define KNIGHT 'N'
#define BISHOP 'B'
#define ROOK 'R'
#define QUEEN 'Q'
#define KING 'K'

// Define Chess Board and Piece structures
typedef struct {
    char type;
    int value;
} ChessPiece;

typedef struct {
    ChessPiece **pieces;
} ChessBoard;

// Method to initialize the Chess Board
void initializeBoard(ChessBoard *board) {
    int i, j;
    char pieceOrder[] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};

    board->pieces = (ChessPiece **) malloc(BOARD_SIZE * sizeof(ChessPiece *));
    for (i = 0; i < BOARD_SIZE; i++) {
        board->pieces[i] = (ChessPiece *) calloc(BOARD_SIZE, sizeof(ChessPiece));
        for (j = 0; j < BOARD_SIZE; j++) {
            if (i == 1) {
                board->pieces[i][j].type = PAWN;
                board->pieces[i][j].value = PAWN_VALUE;
            } else if (i == 0 || i == BOARD_SIZE - 1) {
                board->pieces[i][j].type = pieceOrder[j];
                switch (pieceOrder[j]) {
                    case ROOK:
                        board->pieces[i][j].value = ROOK_VALUE;
                        break;
                    case KNIGHT:
                        board->pieces[i][j].value = KNIGHT_VALUE;
                        break;
                    case BISHOP:
                        board->pieces[i][j].value = BISHOP_VALUE;
                        break;
                    case QUEEN:
                        board->pieces[i][j].value = QUEEN_VALUE;
                        break;
                    case KING:
                        board->pieces[i][j].value = KING_VALUE;
                        break;
                }
            } else {
                board->pieces[i][j].type = EMPTY;
                board->pieces[i][j].value = 0;
            }
        }
    }
}

// Method to print the Chess Board
void printBoard(ChessBoard *board) {
    int i, j;

    printf("\n   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%c  ", i + 'A');
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", BOARD_SIZE - i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c  ", board->pieces[i][j].type);
        }
        printf("%d", BOARD_SIZE - i);
        printf("\n");
    }
    printf("   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%c  ", i + 'A');
    }
    printf("\n\n");
}

// Main method
int main() {
    ChessBoard board;

    initializeBoard(&board);
    printBoard(&board);

    return 0;
}