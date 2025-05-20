//Gemma-7B DATASET v1.0 Category: Chess engine ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOARD_SIZE 64

typedef struct Node {
    struct Node* next;
    char piece;
    int x;
    int y;
} Node;

Node* createNode(char piece, int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->piece = piece;
    newNode->x = x;
    newNode->y = y;
    return newNode;
}

void printBoard(Node* head) {
    int i, j;
    for (i = 0; i < MAX_BOARD_SIZE; i++) {
        for (j = 0; j < MAX_BOARD_SIZE; j++) {
            Node* current = head;
            while (current) {
                if (current->x == i && current->y == j) {
                    printf("%c ", current->piece);
                } else {
                    printf(" . ");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    Node* head = createNode('r', 0, 0);
    head->next = createNode('n', 0, 1);
    head->next->next = createNode('b', 0, 2);
    head->next->next->next = createNode('q', 0, 3);
    head->next->next->next->next = createNode('k', 0, 4);

    printBoard(head);

    return 0;
}