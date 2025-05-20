//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void printBoard(Node* head) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Node* current = head;
            while (current) {
                if (current->x == i && current->y == j) {
                    printf("X ");
                } else {
                    printf(". ");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    Node* head = createNode(0, 0);
    head->next = createNode(1, 0);
    head->next->next = createNode(2, 0);
    head->next->next->next = createNode(0, 1);
    head->next->next->next->next = createNode(1, 1);
    head->next->next->next->next->next = createNode(2, 1);
    head->next->next->next->next->next->next = createNode(0, 2);
    head->next->next->next->next->next->next->next = createNode(1, 2);
    head->next->next->next->next->next->next->next->next = createNode(2, 2);

    printBoard(head);

    return 0;
}