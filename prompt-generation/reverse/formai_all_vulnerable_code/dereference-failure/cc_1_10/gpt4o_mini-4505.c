//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define WHITE_PAWN 'P'
#define BLACK_PAWN 'p'
#define EMPTY ' '

void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int isValidMove(char board[SIZE][SIZE], int fromRow, int fromCol, int toRow, int toCol, char player);
int movePiece(char board[SIZE][SIZE], int fromRow, int fromCol, int toRow, int toCol);
int checkWin(char board[SIZE][SIZE], char player);
void playGame();

int main() {
    playGame();
    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i < 3 && (i + j) % 2 != 0) {
                board[i][j] = BLACK_PAWN;
            } else if (i > 4 && (i + j) % 2 != 0) {
                board[i][j] = WHITE_PAWN;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(char board[SIZE][SIZE], int fromRow, int fromCol, int toRow, int toCol, char player) {
    if (toRow < 0 || toRow >= SIZE || toCol < 0 || toCol >= SIZE || board[toRow][toCol] != EMPTY) {
        return 0; // Target position is out of bounds or occupied
    }
    int direction = (player == WHITE_PAWN) ? 1 : -1;
    if (toRow - fromRow == direction && abs(toCol - fromCol) == 1) {
        return 1; // Simple move
    }
    if (toRow - fromRow == 2 * direction && abs(toCol - fromCol) == 2) {
        int middleRow = fromRow + direction;
        int middleCol = (fromCol + toCol) / 2;
        if (board[middleRow][middleCol] != EMPTY && board[middleRow][middleCol] != player) {
            return 1; // Capture move
        }
    }
    return 0; // Invalid move
}

int movePiece(char board[SIZE][SIZE], int fromRow, int fromCol, int toRow, int toCol) {
    char player = board[fromRow][fromCol];
    if (isValidMove(board, fromRow, fromCol, toRow, toCol, player)) {
        board[toRow][toCol] = player;
        board[fromRow][fromCol] = EMPTY;

        // Capture
        if (abs(toRow - fromRow) == 2) {
            int middleRow = (fromRow + toRow) / 2;
            int middleCol = (fromCol + toCol) / 2;
            board[middleRow][middleCol] = EMPTY; // Remove captured piece
        }
        return 1; // Successful move
    }
    return 0; // Invalid move
}

int checkWin(char board[SIZE][SIZE], char player) {
    char opponent = (player == WHITE_PAWN) ? BLACK_PAWN : WHITE_PAWN;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == opponent) {
                return 0; // Opponent pieces exist
            }
        }
    }
    return 1; // Current player wins
}

void playGame() {
    char board[SIZE][SIZE];
    char currentPlayer = WHITE_PAWN;
    int fromRow, fromCol, toRow, toCol;

    initializeBoard(board);

    while (1) {
        printBoard(board);
        printf("Player %c's Turn. Enter move (e.g., A3 B4): ", (currentPlayer == WHITE_PAWN) ? 'W' : 'B');
        char from[3], to[3];
        scanf("%s %s", from, to);
        
        fromRow = from[1] - '1';
        fromCol = from[0] - 'A';
        toRow = to[1] - '1';
        toCol = to[0] - 'A';

        if (movePiece(board, fromRow, fromCol, toRow, toCol)) {
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                printf("Player %c wins!\n", (currentPlayer == WHITE_PAWN) ? 'W' : 'B');
                return;
            }
            currentPlayer = (currentPlayer == WHITE_PAWN) ? BLACK_PAWN : WHITE_PAWN; // Switch player
        } else {
            printf("Invalid Move! Try again.\n");
        }
    }
}