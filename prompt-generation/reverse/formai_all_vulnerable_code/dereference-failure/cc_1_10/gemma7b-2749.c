//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void initializeBoard(int** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void drawBoard(int** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isBoardFull(int** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int** board = (int**)malloc(sizeof(int*) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (int*)malloc(sizeof(int) * BOARD_SIZE);
    }

    initializeBoard(board);

    int player = 1;
    int move = 0;

    while (!isBoardFull(board) && move < 9) {
        printf("Enter your move (1-9): ");
        scanf("%d", &move);

        if (board[move/3][move%3] == 0) {
            board[move/3][move%3] = player;
            player *= -1;
            move++;
        } else {
            printf("Move not valid.\n");
        }
    }

    drawBoard(board);

    if (isBoardFull(board)) {
        printf("It's a draw!");
    } else {
        printf("Winner: %d", board[move/3][move%3]);
    }

    free(board);

    return 0;
}