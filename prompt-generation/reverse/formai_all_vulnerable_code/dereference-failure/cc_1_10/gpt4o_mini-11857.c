//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef struct {
    char type; // 'P' for Pawn, 'R' for Rook, 'N' for Knight, etc.
    char color; // 'W' for White, 'B' for Black
} Piece;

typedef struct {
    Piece *board[BOARD_SIZE][BOARD_SIZE];
} ChessBoard;

void initializeBoard(ChessBoard *chessboard) {
    // Placing pieces on the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        chessboard->board[1][i] = malloc(sizeof(Piece));
        chessboard->board[1][i]->type = 'P';
        chessboard->board[1][i]->color = 'W';

        chessboard->board[6][i] = malloc(sizeof(Piece));
        chessboard->board[6][i]->type = 'P';
        chessboard->board[6][i]->color = 'B';
    }
    // Rooks
    chessboard->board[0][0] = malloc(sizeof(Piece)); chessboard->board[0][0]->type = 'R'; chessboard->board[0][0]->color = 'W';
    chessboard->board[0][7] = malloc(sizeof(Piece)); chessboard->board[0][7]->type = 'R'; chessboard->board[0][7]->color = 'W';
    chessboard->board[7][0] = malloc(sizeof(Piece)); chessboard->board[7][0]->type = 'R'; chessboard->board[7][0]->color = 'B';
    chessboard->board[7][7] = malloc(sizeof(Piece)); chessboard->board[7][7]->type = 'R'; chessboard->board[7][7]->color = 'B';
}

void printBoard(ChessBoard *chessboard) {
    printf("   a b c d e f g h\n");
    printf("  +----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (chessboard->board[i][j] != NULL) {
                printf("%c ", chessboard->board[i][j]->type);
            } else {
                printf(". ");
            }
        }
        printf("| %d\n", 8 - i);
    }
    printf("  +----------------\n");
    printf("   a b c d e f g h\n");
}

int movePiece(ChessBoard *chessboard, int startX, int startY, int endX, int endY) {
    if (startX < 0 || startX >= BOARD_SIZE || startY < 0 || startY >= BOARD_SIZE ||
        endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) {
        return 0; // Invalid move
    }

    Piece *movingPiece = chessboard->board[startX][startY];
    if (movingPiece == NULL) {
        return 0; // No piece to move
    }

    // Simple movement validation for pawns only as an example
    if (movingPiece->type == 'P') {
        if (movingPiece->color == 'W' && endX == startX + 1 && endY == startY) {
            // Move the pawn forward
            chessboard->board[endX][endY] = movingPiece;
            chessboard->board[startX][startY] = NULL;
            return 1; // Move successful
        } else if (movingPiece->color == 'B' && endX == startX - 1 && endY == startY) {
            // Move the pawn forward
            chessboard->board[endX][endY] = movingPiece;
            chessboard->board[startX][startY] = NULL;
            return 1; // Move successful 
        }
    }
    return 0; // Invalid move
}

void freeBoard(ChessBoard *chessboard) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            free(chessboard->board[i][j]);
        }
    }
}

void loveInTheTimeOfChess() {
    printf("A tale of two pawns, destined to meet...\n");
    printf("Through the wooden battlefield, they shall traverse.\n");
}

int main() {
    ChessBoard myChessBoard = {NULL};
    initializeBoard(&myChessBoard);
    printBoard(&myChessBoard);
    loveInTheTimeOfChess();

    // Simulating moves
    char command[10];
    while (1) {
        printf("Enter move (e.g., 'e2 e3'): ");
        fgets(command, sizeof(command), stdin);
        int startX = 6 - (command[1] - '0'); // Row from the bottom (1-8 to 7-0)
        int startY = command[0] - 'a'; // Column 0-7
        int endX = 6 - (command[4] - '0');
        int endY = command[3] - 'a';

        if (movePiece(&myChessBoard, startX, startY, endX, endY)) {
            printf("Alas, the pawn moves forth!\n\n");
        } else {
            printf("Oh! A move denied, love’s cruel hand holds back the pawn.\n\n");
        }
        printBoard(&myChessBoard);
    }

    freeBoard(&myChessBoard);
    return 0;
}