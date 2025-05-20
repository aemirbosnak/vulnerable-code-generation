//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int move;
    struct Node* next;
} Node;

Node* createMoveList(int move) {
    Node* newNode = malloc(sizeof(Node));
    newNode->move = move;
    newNode->next = NULL;
    return newNode;
}

void insertMove(Node* head, int move) {
    Node* newNode = createMoveList(move);
    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

int isMoveValid(int move, int board[]) {
    return move >= 0 && move < BOARD_SIZE && board[move] == 0;
}

int evaluateBoard(int board[]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == board[i + 1] && board[i] == board[i + 2] && board[i] != 0) {
            return board[i];
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j] == board[j + 1] && board[j] == board[j + 2] && board[j] != 0) {
            return board[j];
        }
    }

    // Check diagonals
    if (board[0] == board[4] && board[0] == board[8] && board[0] != 0) {
        return board[0];
    }

    // If all cells are occupied and no winner, it's a draw
    return 0;
}

int main() {
    int board[BOARD_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int move = 0;
    Node* moveList = NULL;

    // Simulate the game
    while (!evaluateBoard(board) && move < 9) {
        // Get the move
        move = rand() % 9;

        // Check if the move is valid
        if (isMoveValid(move, board)) {
            // Insert the move into the move list
            insertMove(moveList, move);

            // Make the move
            board[move] = 2;
        }
    }

    // Print the winner or draw
    if (evaluateBoard(board) != 0) {
        printf("Winner: Player %d\n", evaluateBoard(board));
    } else {
        printf("Draw\n");
    }

    return 0;
}