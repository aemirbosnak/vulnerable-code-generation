//FormAI DATASET v1.0 Category: Chess engine ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8 // 8x8 Chess board

typedef struct ChessBoard {
    char squares[BOARD_SIZE][BOARD_SIZE];
    bool whiteKingMoved;
    bool blackKingMoved;
} ChessBoard;

ChessBoard* initializeBoard() {
    ChessBoard* board = malloc(sizeof(ChessBoard));
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(i == 0 || i == 7) {
                switch(j) {
                    case 0:
                    case 7:
                        board->squares[i][j] = 'R'; //Rook
                        break;
                    case 1:
                    case 6:
                        board->squares[i][j] = 'N'; //Knight
                        break;
                    case 2:
                    case 5:
                        board->squares[i][j] = 'B'; //Bishop
                        break;
                    case 3:
                        board->squares[i][j] = 'Q'; //Queen
                        break;
                    case 4:
                        board->squares[i][j] = 'K'; //King
                        break;
                }
            } else if(i == 1 || i == 6) {
                board->squares[i][j] = 'P'; //Pawn
            } else {
                board->squares[i][j] = ' '; //Empty square
            }
        }
    }
    board->whiteKingMoved = false;
    board->blackKingMoved = false;
    return board;
}

void printBoard(ChessBoard* board) {
    for(int i = BOARD_SIZE - 1; i >= 0; i--) {
        printf("%d ", i + 1);
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board->squares[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

int main() {
    ChessBoard* board = initializeBoard();
    printBoard(board);
    return 0;
}