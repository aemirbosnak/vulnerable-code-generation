//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void initializeBoard(int **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (int*)malloc(BOARD_SIZE * sizeof(int));
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void displayBoard(int **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int **board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] != 0) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0) {
        return 1;
    }

    // If all cells are occupied and there is no winner, it's a draw
    return 2;
}

int main() {
    int **board;
    initializeBoard(&board);

    // Play the game
    int player = 1;
    while (1) {
        int row, col;
        printf("Enter row and column (1-3): ");
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (board[row][col] != 0) {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        board[row][col] = player;

        // Check if the player has won or there is a draw
        int winner = checkWin(board);
        if (winner == 1) {
            printf("Player %d has won!\n", player);
            break;
        } else if (winner == 2) {
            printf("It's a draw.\n");
            break;
        }

        // Switch to the next player
        player *= -1;
    }

    // Free the memory
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}