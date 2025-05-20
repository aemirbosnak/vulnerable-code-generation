//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* newNode(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void playGame(Node* head) {
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = head->x;
            head = head->next;
        }
    }

    int winner = checkWinner(board);

    if (winner == PLAYER_X) {
        printf("Player X won!");
    } else if (winner == PLAYER_O) {
        printf("Player O won!");
    } else {
        printf("It's a draw!");
    }
}

int checkWinner(int** board) {
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

    // If all else fails, it's a draw
    return 0;
}

int main() {
    Node* head = newNode(0, 0);
    newNode(1, 0);
    newNode(2, 0);
    newNode(0, 1);
    newNode(1, 1);
    newNode(2, 1);
    newNode(0, 2);
    newNode(1, 2);
    newNode(2, 2);

    playGame(head);

    return 0;
}