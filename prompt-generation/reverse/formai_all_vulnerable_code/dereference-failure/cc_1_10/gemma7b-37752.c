//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* newNode(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void displayBoard(Node* head) {
    for (Node* node = head; node; node = node->next) {
        printf("%d ", node->x);
    }
    printf("\n");
}

int isBoardFull(Node* head) {
    for (Node* node = head; node; node = node->next) {
        if (node->x == -1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    Node* head = newNode(0, 0);
    head->next = newNode(1, 0);
    head->next->next = newNode(2, 0);
    head->next->next->next = newNode(0, 1);
    head->next->next->next->next = newNode(1, 1);
    head->next->next->next->next->next = newNode(2, 1);
    head->next->next->next->next->next->next = newNode(0, 2);
    head->next->next->next->next->next->next->next = newNode(1, 2);
    head->next->next->next->next->next->next->next->next = newNode(2, 2);

    displayBoard(head);

    if (isBoardFull(head)) {
        printf("Board is full!\n");
    } else {
        printf("Board is not full.\n");
    }

    return 0;
}