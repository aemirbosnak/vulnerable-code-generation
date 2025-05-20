//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 4

void initBoard(char board[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    for (j = 0; j < COL; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

void playGame(char board[ROW][COL]) {
    int choice, i, j;
    char mark;
    int flag = 0;
    srand(time(NULL));
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            board[i][j] = '-';
        }
    }
    while (flag == 0) {
        printf("Player 1's turn\n");
        printf("Enter row and column: ");
        scanf("%d%d", &i, &j);
        if (board[i][j]!= '-') {
            printf("Invalid move\n");
            continue;
        }
        board[i][j] = 'X';
        flag = checkWin(board);
        if (flag == 1) {
            printf("Player 1 wins!\n");
            break;
        }
        if (j == 2) {
            i++;
            j = 0;
        } else {
            j++;
        }
    }
    while (flag == 0) {
        printf("Player 2's turn\n");
        printf("Enter row and column: ");
        scanf("%d%d", &i, &j);
        if (board[i][j]!= '-') {
            printf("Invalid move\n");
            continue;
        }
        board[i][j] = 'O';
        flag = checkWin(board);
        if (flag == 1) {
            printf("Player 2 wins!\n");
            break;
        }
        if (j == 2) {
            i++;
            j = 0;
        } else {
            j++;
        }
    }
    if (flag == 0) {
        printf("It's a draw!\n");
    }
}

int main() {
    char board[ROW][COL];
    initBoard(board);
    playGame(board);
    return 0;
}