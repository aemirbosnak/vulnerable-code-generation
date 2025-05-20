//Falcon-180B DATASET v1.0 Category: Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void drawBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
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

void playGame(int board[SIZE][SIZE]) {
    int player = 1;
    int choice;
    while (1) {
        system("clear");
        drawBoard(board);
        printf("Player %d's turn\n", player);
        printf("Enter your move: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > SIZE * SIZE) {
            printf("Invalid move\n");
            continue;
        }
        if (board[choice / SIZE][choice % SIZE]!= 0) {
            printf("Spot taken\n");
            continue;
        }
        board[choice / SIZE][choice % SIZE] = player;
        if (checkWin(board)) {
            printf("Player %d wins!\n", player);
            break;
        }
        player =!player;
    }
}

int main() {
    srand(time(0));
    int board[SIZE][SIZE] = {0};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }
    playGame(board);
    return 0;
}