//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
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
        board[i] = (int*)malloc(BOARD_SIZE * sizeof(int));
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void printBoard(int** board) {
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

int checkWin(int** board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0) {
            return board[0][i];
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] != 0) {
            return board[j][0];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0) {
        return board[0][0];
    }

    // If all cells are filled and no winner, it's a draw
    return 0;
}

int main() {
    int** board = (int**)malloc(BOARD_SIZE * sizeof(int*));
    initializeBoard(board);

    int player = 1;
    int gameWon = 0;

    while (!gameWon && !isBoardFull(board)) {
        int row, column;
        printf("Enter row and column (1-2): ");
        scanf("%d %d", &row, &column);

        if (board[row][column] == 0) {
            board[row][column] = player;
            printBoard(board);

            gameWon = checkWin(board);
            if (gameWon) {
                printf("Congratulations! Player %d won!", player);
            } else {
                player = (player == 1) ? 2 : 1;
            }
        } else {
            printf("Error: cell already occupied.\n");
        }
    }

    if (gameWon) {
        printBoard(board);
    } else {
        printf("It's a draw!");
    }

    free(board);
    return 0;
}