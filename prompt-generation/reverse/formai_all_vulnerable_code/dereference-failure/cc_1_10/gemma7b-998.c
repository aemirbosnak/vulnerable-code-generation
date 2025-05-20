//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* newNode(int x, int y) {
    Node* newNode = malloc(sizeof(struct Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Create the game board
    int board[BOARD_SIZE][BOARD_SIZE] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

    // Create the move list
    Node* moveList = NULL;

    // Player's turn
    int playerTurn = 1;

    // Game loop
    while (!checkWin(board, moveList) && !boardFull(board)) {
        // Get the player's move
        int moveX = rand() % BOARD_SIZE;
        int moveY = rand() % BOARD_SIZE;

        // Check if the move is valid
        if (!isValidMove(board, moveX, moveY, moveList)) {
            continue;
        }

        // Make the move
        board[moveX][moveY] = playerTurn;

        // Add the move to the move list
        moveList = newNode(moveX, moveY);

        // Switch turns
        playerTurn *= -1;
    }

    // Check if the player won or if the game ended in a draw
    if (checkWin(board, moveList)) {
        printf("Player %d won!", playerTurn);
    } else if (boardFull(board)) {
        printf("It's a draw!");
    } else {
        printf("An error occurred.");
    }

    return 0;
}

int checkWin(int** board, Node* moveList) {
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

    // No win, so return 0
    return 0;
}

int boardFull(int** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }

    // The board is full, so return 1
    return 1;
}

int isValidMove(int** board, int moveX, int moveY, Node* moveList) {
    // Check if the move is within the board boundaries
    if (moveX < 0 || moveX >= BOARD_SIZE || moveY < 0 || moveY >= BOARD_SIZE) {
        return 0;
    }

    // Check if the move has already been made
    if (moveList != NULL && moveList->x == moveX && moveList->y == moveY) {
        return 0;
    }

    // Check if the move is valid
    return 1;
}