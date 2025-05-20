//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

char **board;
char currentPlayerMark;

void initializeBoard() {
    board = (char **) malloc(SIZE * sizeof(char *));
    for(int i = 0; i < SIZE; i++) {
        board[i] = (char *) malloc(SIZE * sizeof(char));
    }

    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            board[row][col] = ' ';
        }
    }
}

void displayBoard() {
    printf("\n\n");
    for(int row = 0; row < SIZE; row++) {
        printf("\t\t\t\t  %c   |   %c   |   %c   \n", board[row][0], board[row][1], board[row][2]);
        if(row != SIZE - 1) {
            printf("\t\t\t\t------------------\n");
        }
    }
    printf("\n\n");
}

bool isBoardFull() {
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            if(board[row][col] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool checkForWin() {
    for(int row = 0; row < SIZE; row++) {
        if(board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != ' ') {
            return true;
        }
    }

    for(int col = 0; col < SIZE; col++) {
        if(board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != ' ') {
            return true;
        }
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }

    if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {
        return true;
    }

    return false;
}

void changePlayer() {
    if(currentPlayerMark == 'X') {
        currentPlayerMark = 'O';
    } else {
        currentPlayerMark = 'X';
    }
}

bool placeMark(int row, int col) {
    if(row <= SIZE - 1 && col <= SIZE - 1 && board[row][col] == ' ') {
        board[row][col] = currentPlayerMark;
        return true;
    }
    return false;
}

int minimax(bool isMaximizing) {
    if(checkForWin() && currentPlayerMark == 'X') {
        return 10;
    } else if(checkForWin() && currentPlayerMark == 'O') {
        return -10;
    } else if(isBoardFull()) {
        return 0;
    }

    int bestScore;
    int score;

    if(isMaximizing) {
        bestScore = -1000;
        for(int row = 0; row < SIZE; row++) {
            for(int col = 0; col < SIZE; col++) {
                if(board[row][col] == ' ') {
                    board[row][col] = 'X';
                    currentPlayerMark = 'X';
                    score = minimax(false);
                    board[row][col] = ' ';
                    if(score > bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    } else {
        bestScore = 1000;
        for(int row = 0; row < SIZE; row++) {
            for(int col = 0; col < SIZE; col++) {
                if(board[row][col] == ' ') {
                    board[row][col] = 'O';
                    currentPlayerMark = 'O';
                    score = minimax(true);
                    board[row][col] = ' ';
                    if(score < bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
}

void getComputerMove() {
    int row, col;
    int bestScore = -1000;
    int score;

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'X';
                currentPlayerMark = 'X';
                score = minimax(false);
                board[i][j] = ' ';
                if(score > bestScore) {
                    bestScore = score;
                    row = i;
                    col = j;
                }
            }
        }
    }
    placeMark(row, col);
}

int main() {
    printf("\n\t\t\t\t\tWelcome to Tic-Tac-Toe AI!\n\n");
    initializeBoard();
    displayBoard();
    int row, col;
    currentPlayerMark = 'O';

    while(!isBoardFull() && !checkForWin()) {
        printf("\n\n\t\t\t\tEnter row number and column number (1-3) to place a mark (O): ");
        scanf("%d %d", &row, &col);
        if(placeMark(row-1, col-1)) {
            displayBoard();
            changePlayer();
            if(!isBoardFull() && !checkForWin()) {
                printf("\n\n\t\t\t\tIt's the computer's turn...\n\n");
                getComputerMove();
                displayBoard();
                changePlayer();
            }
        } else {
            printf("\n\t\t\tInvalid move! Please try again.\n");
        }
    }

    if(checkForWin()) {
        changePlayer();
        printf("\n\n\t\t\t\t%s wins!\n\n", (currentPlayerMark == 'X') ? "Computer" : "You");
    } else {
        printf("\n\n\t\t\t\tIt's a tie!\n\n");
    }

    for(int i = 0; i < SIZE; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}