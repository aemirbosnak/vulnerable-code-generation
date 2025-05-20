//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

typedef struct {
    char board[SIZE][SIZE];
} ChessBoard;

void initializeBoard(ChessBoard *chess) {
    const char *init[] = {
        "rnbqkbnr",
        "pppppppp",
        "        ",
        "        ",
        "        ",
        "        ",
        "PPPPPPPP",
        "RNBQKBNR"
    };

    for (int i = 0; i < SIZE; i++) {
        strcpy(chess->board[i], init[i]);
    }
}

void printBoard(const ChessBoard *chess) {
    printf("  a b c d e f g h\n");
    printf("  -----------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d|", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", chess->board[i][j] == ' ' ? '.' : chess->board[i][j]);
        }
        printf("|\n");
    }
    printf("  -----------------\n");
}

int isValidMove(const char *move) {
    return strlen(move) == 4 && move[0] >= 'a' && move[0] <= 'h' && 
           move[1] >= '1' && move[1] <= '8' && move[2] >= 'a' && 
           move[2] <= 'h' && move[3] >= '1' && move[3] <= '8';
}

void movePiece(ChessBoard *chess, const char *move) {
    int fromX = SIZE - (move[1] - '0') - 1;
    int fromY = move[0] - 'a';
    int toX = SIZE - (move[3] - '0') - 1;
    int toY = move[2] - 'a';

    chess->board[toX][toY] = chess->board[fromX][fromY];
    chess->board[fromX][fromY] = ' ';
}

void playGame() {
    ChessBoard chess;
    initializeBoard(&chess);
    char move[5];
    int turn = 0;

    while (1) {
        printBoard(&chess);
        if (turn % 2 == 0) {
            printf("Romeo, your turn (e.g., e2e4): ");
        } else {
            printf("Juliet, your turn (e.g., e7e5): ");
        }
        
        fgets(move, sizeof(move), stdin);
        move[strcspn(move, "\n")] = 0;

        if (isValidMove(move)) {
            movePiece(&chess, move);
            turn++;
        } else {
            printf("A false move leads to tragic despair!\n");
        }
    }
}

int main() {
    printf("Welcome to the Tragic Chess of Romeo and Juliet!\n");
    playGame();
    return 0;
}