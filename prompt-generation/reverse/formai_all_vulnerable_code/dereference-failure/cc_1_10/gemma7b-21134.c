//Gemma-7B DATASET v1.0 Category: Chess engine ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 64

typedef struct Node {
    int piece, move, color, next;
} Node;

Node* createNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    node->piece = 0;
    node->move = 0;
    node->color = 0;
    node->next = NULL;
    return node;
}

void insertNode(Node* head, int piece, int move, int color) {
    Node* newNode = createNode();
    newNode->piece = piece;
    newNode->move = move;
    newNode->color = color;
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void printMoves(Node* head) {
    while (head) {
        printf("%d-%d (%c) ", head->move, head->piece);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    insertNode(head, 1, 5, 1);
    insertNode(head, 2, 1, 2);
    insertNode(head, 3, 2, 1);
    insertNode(head, 4, 3, 2);
    insertNode(head, 5, 4, 1);

    printMoves(head);

    return 0;
}