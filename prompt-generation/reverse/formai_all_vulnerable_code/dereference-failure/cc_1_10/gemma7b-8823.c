//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: intelligent
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3
#define MOVE_SIZE 2

typedef struct Node {
    int move;
    struct Node* next;
} Node;

Node* createMoveList(int size) {
    Node* head = malloc(sizeof(Node));
    head->move = size;
    head->next = NULL;
    return head;
}

int evaluateBoard(char** board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (board[r][c] == 'X' && (r == 0 || board[r - 1][c] == 'X' || board[r][c - 1] == 'X' || board[r][c + 1] == 'X')) {
                return 1;
            } else if (board[r][c] == 'O' && (r == 0 || board[r - 1][c] == 'O' || board[r][c - 1] == 'O' || board[r][c + 1] == 'O')) {
                return 2;
            }
        }
    }

    return 0;
}

int main() {
    char** board = malloc(sizeof(char*) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = malloc(sizeof(char) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    Node* moveList = createMoveList(10);

    // Game loop
    int gameWon = 0;
    char currentPlayer = 'X';

    while (!gameWon) {
        // Get the move
        int move = moveList->move;
        moveList = moveList->next;

        // Make the move
        board[move / BOARD_SIZE][move % BOARD_SIZE] = currentPlayer;

        // Evaluate the board
        gameWon = evaluateBoard(board);

        // Change the current player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Print the winner
    printf("The winner is: %c\n", currentPlayer);

    return 0;
}