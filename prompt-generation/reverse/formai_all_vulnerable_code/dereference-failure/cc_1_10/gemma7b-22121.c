//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: accurate
#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 3

typedef struct Node {
    int row, col;
    struct Node* next;
} Node;

Node* createNode(int row, int col) {
    Node* node = malloc(sizeof(Node));
    node->row = row;
    node->col = col;
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

int isBoardFull(Node* head) {
    while (head) {
        if (head->row == BOARD_SIZE - 1) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int main() {
    Node* head = createNode(0, 0);
    insertNode(head, createNode(0, 1));
    insertNode(head, createNode(0, 2));
    insertNode(head, createNode(1, 0));
    insertNode(head, createNode(1, 1));
    insertNode(head, createNode(1, 2));
    insertNode(head, createNode(2, 0));
    insertNode(head, createNode(2, 1));
    insertNode(head, createNode(2, 2));

    if (isBoardFull(head)) {
        printf("The board is full.");
    } else {
        printf("The board is not full.");
    }

    return 0;
}