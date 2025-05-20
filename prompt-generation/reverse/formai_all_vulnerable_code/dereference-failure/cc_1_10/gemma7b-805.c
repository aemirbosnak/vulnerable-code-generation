//Gemma-7B DATASET v1.0 Category: Chess AI ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 64

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void createBoard(Node** head) {
    *head = NULL;
    for (int i = 0; i < BOARD_SIZE; i++) {
        Node* newNode = malloc(sizeof(Node));
        newNode->x = i;
        newNode->y = -1;
        newNode->next = *head;
        *head = newNode;
    }
}

void placePiece(Node* head, int x, int y) {
    for (Node* current = head; current; current = current->next) {
        if (current->x == x && current->y == y) {
            current->y = y;
            return;
        }
    }

    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = head;
    head = newNode;
}

int main() {
    Node* head = NULL;
    createBoard(&head);
    placePiece(head, 0, 0);
    placePiece(head, 1, 1);
    placePiece(head, 2, 2);

    for (Node* current = head; current; current = current->next) {
        printf("(%d, %d)\n", current->x, current->y);
    }

    return 0;
}