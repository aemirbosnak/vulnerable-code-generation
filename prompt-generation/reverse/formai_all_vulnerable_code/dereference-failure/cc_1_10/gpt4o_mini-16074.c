//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define EMPTY ' '

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} ChessBoard;

void initializeBoard(ChessBoard *chess) {
    const char initBoard[BOARD_SIZE][BOARD_SIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            chess->board[i][j] = initBoard[i][j];
        }
    }
}

void printBoard(ChessBoard *chess) {
    printf("\n  a b c d e f g h\n");
    printf(" +----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", chess->board[i][j]);
        }
        printf("|\n");
    }
    printf(" +----------------\n");
}

int isMoveValid(char piece, int fromRow, int fromCol, int toRow, int toCol) {
    // Simplified move validation for Bishop Only for Puzzling Style
    if (piece == 'B' || piece == 'b') {
        int rowDiff = abs(toRow - fromRow);
        int colDiff = abs(toCol - fromCol);
        return rowDiff == colDiff;
    }
    return 0; // Not a valid move for other pieces
}

void makeMove(ChessBoard *chess, int fromRow, int fromCol, int toRow, int toCol) {
    char piece = chess->board[fromRow][fromCol];
    if (isMoveValid(piece, fromRow, fromCol, toRow, toCol)) {
        chess->board[toRow][toCol] = piece;
        chess->board[fromRow][fromCol] = EMPTY;
    } else {
        printf("Invalid move!\n");
    }
}

void parseInput(const char *input, int *fromRow, int *fromCol, int *toRow, int *toCol) {
    *fromCol = input[0] - 'a';
    *fromRow = BOARD_SIZE - (input[1] - '0');
    *toCol = input[3] - 'a';
    *toRow = BOARD_SIZE - (input[4] - '0');
}

int main() {
    ChessBoard chess;
    initializeBoard(&chess);
    printBoard(&chess);
    
    char input[6];
    while (1) {
        printf("Enter your move (e.g., e2 e4): ");
        fgets(input, sizeof(input), stdin);
        
        if (input[0] == 'q') {
            break;
        }
        
        int fromRow, fromCol, toRow, toCol;
        parseInput(input, &fromRow, &fromCol, &toRow, &toCol);
        
        makeMove(&chess, fromRow, fromCol, toRow, toCol);
        printBoard(&chess);
    }
    
    return 0;
}