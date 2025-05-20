//FormAI DATASET v1.0 Category: Chess AI ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char piece; // piece type ('P', 'K', 'Q', 'R', 'N', 'B')
    int color; // 0 for white, 1 for black
    int row; // row number (0-7)
    int col; // column letter (0-7)
} ChessPiece;

char board[8][8] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

ChessPiece *getPieceAt(int row, int col) {
    ChessPiece *selectedPiece = malloc(sizeof(ChessPiece));
    selectedPiece->piece = board[row][col];
    selectedPiece->row = row;
    selectedPiece->col = col;

    // Check if it's a white or black piece
    if (board[row][col] >= 'A' && board[row][col] <= 'Z') {
        selectedPiece->color = 0; // white
    } else if (board[row][col] >= 'a' && board[row][col] <= 'z') {
        selectedPiece->color = 1; // black
    } else {
        selectedPiece->color = -1; // empty space
    }
    return selectedPiece;
}

void printBoard() {
    printf("\n    A    B    C    D    E    F    G    H\n");
    printf("  +----+----+----+----+----+----+----+----+\n");
    for (int row = 0; row < 8; row++) {
        printf("%d ", row + 1);
        for (int col = 0; col < 8; col++) {
            printf("| %c ", board[row][col]);
        }
        printf("| %d\n", row + 1);
        printf("  +----+----+----+----+----+----+----+----+\n");
    }
    printf("    A    B    C    D    E    F    G    H\n");
}

int main() {
    printBoard();
    ChessPiece *piece = getPieceAt(0, 0);
    printf("\nSelected piece: %c %d %d %d\n", piece->piece, piece->color, piece->row, piece->col);
    return 0;
}