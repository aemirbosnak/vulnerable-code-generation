//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: decentralized
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

void insertNode(Node* head, int x, int y) {
    Node* newNode = createNode(x, y);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

int isBoardFull(Node* head) {
    while (head) {
        if (head->x == BOARD_SIZE - 1 && head->y == BOARD_SIZE - 1) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int main() {
    Node* head = NULL;
    insertNode(head, 0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 0, 1);
    insertNode(head, 1, 1);
    insertNode(head, 2, 1);
    insertNode(head, 0, 2);
    insertNode(head, 1, 2);
    insertNode(head, 2, 2);

    if (isBoardFull(head)) {
        printf("The board is full.\n");
    } else {
        printf("The board is not full.\n");
    }

    return 0;
}