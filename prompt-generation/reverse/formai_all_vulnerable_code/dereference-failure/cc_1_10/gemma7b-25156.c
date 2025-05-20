//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void insertNode(Node** head, int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
        *head = newNode;
    }
}

int findPath(Node* head, int targetX, int targetY) {
    if (head == NULL) {
        return 0;
    }

    if (head->x == targetX && head->y == targetY) {
        return 1;
    }

    findPath(head->next, targetX, targetY);

    if (findPath(head->next, targetX, targetY) == 1) {
        return 1;
    }

    return 0;
}

int main() {
    Node* head = NULL;
    insertNode(&head, 0, 0);
    insertNode(&head, 1, 0);
    insertNode(&head, 2, 0);
    insertNode(&head, 3, 0);
    insertNode(&head, 4, 0);
    insertNode(&head, 0, 1);
    insertNode(&head, 1, 1);
    insertNode(&head, 2, 1);
    insertNode(&head, 3, 1);
    insertNode(&head, 4, 1);

    int targetX = 3;
    int targetY = 1;

    if (findPath(head, targetX, targetY) == 1) {
        printf("Path found!");
    } else {
        printf("Path not found!");
    }

    return 0;
}