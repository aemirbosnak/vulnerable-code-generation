//Gemma-7B DATASET v1.0 Category: Chess AI ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 64

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* insertNode(Node* head, int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void printBoard(Node* head) {
    while (head) {
        printf("(%d, %d) ", head->x, head->y);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insertNode(head, 0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 3, 0);
    insertNode(head, 4, 0);
    insertNode(head, 5, 0);

    insertNode(head, 0, 1);
    insertNode(head, 1, 1);
    insertNode(head, 2, 1);
    insertNode(head, 3, 1);
    insertNode(head, 4, 1);
    insertNode(head, 5, 1);

    printBoard(head);

    return 0;
}