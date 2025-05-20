//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int checkWin(char board[3][3], char symbol);  // function to check if someone has won
int checkDraw(char board[3][3]);  // function to check if the game is a draw
void printBoard(char board[3][3]);  // function to print the current state of the board
void makeMove(char board[3][3], int row, int col, char symbol);  // function to make a move on the board
int minimax(char board[3][3], int depth, int isMax, char aiSymbol, char playerSymbol);  // function to implement the minimax algorithm for the AI

int main(void) {
    char board[3][3] = {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };

    char playerSymbol, aiSymbol;
    printf("Welcome to Tic Tac Toe!\n");
    printf("Choose your symbol (X/O): ");
    scanf(" %c", &playerSymbol);

    if (playerSymbol == 'X') {
        aiSymbol = 'O';
    } else {
        aiSymbol = 'X';
    }

    int isPlayersTurn = 1;
    while (1) {
        if (isPlayersTurn) {
            printf("Player's turn: ");
            int row, col;
            scanf("%d %d", &row, &col);
            if (board[row][col] == '_') {
                makeMove(board, row, col, playerSymbol);
                printBoard(board);
                if (checkWin(board, playerSymbol)) {
                    printf("Player wins!\n");
                    break;
                } else if (checkDraw(board)) {
                    printf("It's a draw!\n");
                    break;
                } else {
                    isPlayersTurn = 0;
                }
            } else {
                printf("Invalid move! Try again.\n");
            }
        } else {
            printf("AI's turn:\n");
            int bestScore = -1000;
            int bestRow, bestCol;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == '_') {
                        board[i][j] = aiSymbol;
                        int score = minimax(board, 0, 0, aiSymbol, playerSymbol);
                        board[i][j] = '_';
                        if (score > bestScore) {
                            bestScore = score;
                            bestRow = i;
                            bestCol = j;
                        }
                    }
                }
            }
            makeMove(board, bestRow, bestCol, aiSymbol);
            printBoard(board);
            if (checkWin(board, aiSymbol)) {
                printf("AI wins!\n");
                break;
            } else if (checkDraw(board)) {
                printf("It's a draw!\n");
                break;
            } else {
                isPlayersTurn = 1;
            }
        }
    }

    return 0;
}

int checkWin(char board[3][3], char symbol) {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }

    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
            return 1;
        }
    }

    // check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }

    return 0;
}

int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '_') {
                return 0;
            }
        }
    }
    return 1;
}

void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void makeMove(char board[3][3], int row, int col, char symbol) {
    board[row][col] = symbol;
}

int minimax(char board[3][3], int depth, int isMax, char aiSymbol, char playerSymbol) {
    if (checkWin(board, aiSymbol)) {
        return 10 - depth;
    } else if (checkWin(board, playerSymbol)) {
        return -10 + depth;
    } else if (checkDraw(board)) {
        return 0;
    }

    if (isMax) {
        int bestScore = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = aiSymbol;
                    int score = minimax(board, depth+1, 0, aiSymbol, playerSymbol);
                    board[i][j] = '_';
                    if (score > bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = playerSymbol;
                    int score = minimax(board, depth+1, 1, aiSymbol, playerSymbol);
                    board[i][j] = '_';
                    if (score < bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
}