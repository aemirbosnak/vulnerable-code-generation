//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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
        newNode->next = head;
        head = newNode;
    }
}

int main() {
    Node* head = NULL;
    insertNode(head, 0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 3, 0);
    insertNode(head, 4, 0);

    insertNode(head, 0, 1);
    insertNode(head, 1, 1);
    insertNode(head, 2, 1);
    insertNode(head, 3, 1);

    insertNode(head, 0, 2);
    insertNode(head, 1, 2);
    insertNode(head, 2, 2);
    insertNode(head, 3, 2);

    insertNode(head, 0, 3);
    insertNode(head, 1, 3);
    insertNode(head, 2, 3);
    insertNode(head, 3, 3);

    insertNode(head, 0, 4);
    insertNode(head, 1, 4);
    insertNode(head, 2, 4);
    insertNode(head, 3, 4);

    // Traverse the linked list
    Node* current = head;
    while (current) {
        printf("(%d, %d)\n", current->x, current->y);
        current = current->next;
    }

    return 0;
}