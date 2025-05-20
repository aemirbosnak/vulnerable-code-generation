//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void initializeMaze(Node** head) {
    *head = NULL;
}

void insertNode(Node** head, int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int findPath(Node* head, int targetX, int targetY) {
    if (head == NULL) {
        return 0;
    }

    if (head->x == targetX && head->y == targetY) {
        return 1;
    }

    int path = findPath(head->next, targetX, targetY);

    if (path) {
        return 1;
    }

    return 0;
}

int main() {
    Node* head = NULL;
    initializeMaze(&head);

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
    insertNode(&head, 0, 2);
    insertNode(&head, 1, 2);
    insertNode(&head, 2, 2);
    insertNode(&head, 3, 2);
    insertNode(&head, 4, 2);

    int targetX = 3;
    int targetY = 2;

    if (findPath(head, targetX, targetY)) {
        printf("Path found!");
    } else {
        printf("No path found!");
    }

    return 0;
}