//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void playTicTacToe(int** board, Node* moves) {
    int i, j, move, win = 0;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == moves->data) {
                board[i][j] = -1;
            }
        }
    }

    // Check for win
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != 0) {
            win = 1;
        }
    }

    for (j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != 0) {
            win = 1;
        }
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0) {
        win = 1;
    }

    if (win) {
        printf("You win!");
    } else {
        printf("It's a draw!");
    }
}

int main() {
    int** board = malloc(sizeof(int*) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = malloc(sizeof(int) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    Node* moves = insertAtTail(NULL, 1);
    insertAtTail(moves, 2);
    insertAtTail(moves, 3);
    insertAtTail(moves, 4);
    insertAtTail(moves, 5);

    playTicTacToe(board, moves);

    return 0;
}