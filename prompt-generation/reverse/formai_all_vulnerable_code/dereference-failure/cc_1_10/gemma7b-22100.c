//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void insertNode(Node* node, Node* newNode) {
    if (node == NULL) {
        node = newNode;
    } else {
        node->next = newNode;
        node = newNode;
    }
}

int isValidMove(Node* board, int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return 0;
    }

    for (Node* node = board; node != NULL; node++) {
        if (node->x == x && node->y == y) {
            return 0;
        }
    }

    return 1;
}

int main() {
    Node* board = createNode(0, 0);
    insertNode(board, createNode(1, 0));
    insertNode(board, createNode(2, 0));
    insertNode(board, createNode(0, 1));
    insertNode(board, createNode(1, 1));
    insertNode(board, createNode(0, 2));

    if (isValidMove(board, 1, 2) == 1) {
        printf("Valid move\n");
    } else {
        printf("Invalid move\n");
    }

    return 0;
}