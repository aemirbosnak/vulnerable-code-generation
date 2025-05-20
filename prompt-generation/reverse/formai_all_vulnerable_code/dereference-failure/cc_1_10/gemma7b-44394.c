//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* newNode = malloc(sizeof(struct Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node* head, int x, int y) {
    Node* newNode = createNode(x, y);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printBoard(Node* head) {
    Node* current = head;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (current && current->x == i && current->y == j) {
                printf("O ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
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

    printBoard(head);

    return 0;
}