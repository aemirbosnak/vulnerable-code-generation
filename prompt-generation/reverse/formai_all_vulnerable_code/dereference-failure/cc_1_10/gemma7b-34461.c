//Gemma-7B DATASET v1.0 Category: Chess AI ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BOARD_SIZE 64

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
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printBoard(Node* head) {
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            Node* node = head;
            while (node) {
                if (node->x == i && node->y == j) {
                    printf("x");
                } else {
                    printf(".");
                }
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
    insertNode(head, 3, 0);
    insertNode(head, 4, 0);
    insertNode(head, 5, 0);
    insertNode(head, 6, 0);
    insertNode(head, 0, 1);
    insertNode(head, 1, 1);
    insertNode(head, 2, 1);
    insertNode(head, 3, 1);
    insertNode(head, 4, 1);
    insertNode(head, 5, 1);
    insertNode(head, 6, 1);
    printBoard(head);
    return 0;
}