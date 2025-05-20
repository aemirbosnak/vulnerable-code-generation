//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Node {
    int move;
    struct Node* next;
} Node;

Node* createMoveList(int size) {
    Node* head = malloc(sizeof(Node));
    head->move = -1;
    head->next = NULL;

    for (int i = 0; i < size - 1; i++) {
        Node* newNode = malloc(sizeof(Node));
        newNode->move = -1;
        newNode->next = NULL;
        head->next = newNode;
        head = newNode;
    }

    return head;
}

void playMove(Node* moveList, int move, int board[]) {
    moveList->move = move;
    board[move] = 2;
}

int evaluateBoard(int board[]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == board[i + 1] && board[i] == board[i + 2] && board[i] != 0) {
            return board[i] - 1;
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == board[i + BOARD_SIZE] && board[i] == board[i + 2 * BOARD_SIZE] && board[i] != 0) {
            return board[i] - 1;
        }
    }

    // Check diagonals
    if (board[0] == board[BOARD_SIZE - 1] && board[0] == board[BOARD_SIZE * 2 - 1] && board[0] != 0) {
        return board[0] - 1;
    }

    // No winner, draw
    return 0;
}

int main() {
    int board[BOARD_SIZE * BOARD_SIZE] = {0};
    Node* moveList = createMoveList(10);

    // Play your moves here
    playMove(moveList, 5, board);
    playMove(moveList, 2, board);
    playMove(moveList, 9, board);

    // Check for winner or draw
    int winner = evaluateBoard(board);

    // Print winner or draw
    if (winner) {
        printf("Winner: Player %d\n", winner);
    } else {
        printf("Draw\n");
    }

    return 0;
}