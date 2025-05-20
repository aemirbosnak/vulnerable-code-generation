//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

int isBoardFull(Node* head) {
    for (Node* current = head; current; current = current->next) {
        if (current->x == -1) {
            return 0;
        }
    }
    return 1;
}

int findEmptyPosition(Node* head) {
    for (Node* current = head; current; current = current->next) {
        if (current->x == -1) {
            return current->y;
        }
    }
    return -1;
}

int makeMove(Node* head, int x, int y) {
    Node* newNode = createNode(x, y);
    newNode->next = head;
    head = newNode;
    return 1;
}

int isWon(Node* head, int player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (head->x == player && head->y == i) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (head->x == j && head->y == player) {
            return 1;
        }
    }

    // Check diagonals
    if (head->x == head->y && head->x == player) {
        return 1;
    }

    return 0;
}

int main() {
    Node* head = createNode(0, 0);
    makeMove(head, 0, 0);
    makeMove(head, 1, 0);
    makeMove(head, 2, 0);
    makeMove(head, 0, 1);
    makeMove(head, 1, 1);
    makeMove(head, 2, 1);

    if (isWon(head, 1)) {
        printf("Player 1 won!");
    } else if (isBoardFull(head)) {
        printf("It's a draw!");
    } else {
        printf("Next move:");
    }

    return 0;
}