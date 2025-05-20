//Falcon2-11B DATASET v1.0 Category: Chess engine ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char color;
    int rank;
} Piece;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int x;
    int y;
} Move;

int whiteKingRank = 4;
int blackKingRank = 4;

Piece *whitePieces = NULL;
Piece *blackPieces = NULL;

Position *whitePositions = NULL;
Position *blackPositions = NULL;

Move *whiteMoves = NULL;
Move *blackMoves = NULL;

void initializePieces() {
    whitePieces = (Piece *) malloc(sizeof(Piece) * 8);
    blackPieces = (Piece *) malloc(sizeof(Piece) * 8);

    memset(whitePieces, 0, sizeof(Piece) * 8);
    memset(blackPieces, 0, sizeof(Piece) * 8);
}

void initializePositions() {
    whitePositions = (Position *) malloc(sizeof(Position) * 64);
    blackPositions = (Position *) malloc(sizeof(Position) * 64);

    memset(whitePositions, 0, sizeof(Position) * 64);
    memset(blackPositions, 0, sizeof(Position) * 64);
}

void initializeMoves() {
    whiteMoves = (Move *) malloc(sizeof(Move) * 64);
    blackMoves = (Move *) malloc(sizeof(Move) * 64);

    memset(whiteMoves, 0, sizeof(Move) * 64);
    memset(blackMoves, 0, sizeof(Move) * 64);
}

void parseBoard(char *board) {
    char piece[3];
    int rank;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i * 8 + j] == 'w') {
                whitePieces[i].color = 'w';
            } else if (board[i * 8 + j] == 'b') {
                blackPieces[i].color = 'b';
            }

            piece[0] = board[i * 8 + j];
            piece[1] = board[i * 8 + j + 1];
            piece[2] = '\0';

            rank = strtol(piece, NULL, 10);
            whitePieces[i].rank = rank;
            blackPieces[i].rank = rank;
        }
    }
}

void calculateWhiteMoves() {
    for (int i = 0; i < 8; i++) {
        Position whitePos = {whitePositions[i].x, whitePositions[i].y};

        for (int j = 0; j < 8; j++) {
            Position targetPos = {whitePos.x + j, whitePos.y};

            if (targetPos.x >= 0 && targetPos.x < 8 && targetPos.y >= 0 && targetPos.y < 8) {
                if (whitePieces[i].color == 'w' && whitePieces[i].rank!= whiteKingRank) {
                    Move whiteMove = {whitePos.x, whitePos.y, targetPos.x, targetPos.y};
                    whiteMoves[i] = whiteMove;
                }
            }
        }
    }
}

void calculateBlackMoves() {
    for (int i = 0; i < 8; i++) {
        Position blackPos = {blackPositions[i].x, blackPositions[i].y};

        for (int j = 0; j < 8; j++) {
            Position targetPos = {blackPos.x + j, blackPos.y};

            if (targetPos.x >= 0 && targetPos.x < 8 && targetPos.y >= 0 && targetPos.y < 8) {
                if (blackPieces[i].color == 'b' && blackPieces[i].rank!= blackKingRank) {
                    Move blackMove = {blackPos.x, blackPos.y, targetPos.x, targetPos.y};
                    blackMoves[i] = blackMove;
                }
            }
        }
    }
}

int main() {
    char board[64][8];
    char move[64][8];

    initializePieces();
    initializePositions();
    initializeMoves();

    parseBoard(board);
    calculateWhiteMoves();
    calculateBlackMoves();

    printf("White moves:\n");
    for (int i = 0; i < 8; i++) {
        if (whiteMoves[i].x!= 0 && whiteMoves[i].y!= 0) {
            printf("%d %d -> %d %d\n", whiteMoves[i].x, whiteMoves[i].y, whiteMoves[i].x + 1, whiteMoves[i].y + 1);
        }
    }

    printf("Black moves:\n");
    for (int i = 0; i < 8; i++) {
        if (blackMoves[i].x!= 0 && blackMoves[i].y!= 0) {
            printf("%d %d -> %d %d\n", blackMoves[i].x, blackMoves[i].y, blackMoves[i].x + 1, blackMoves[i].y + 1);
        }
    }

    return 0;
}