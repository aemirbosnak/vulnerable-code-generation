//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
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
    }
}

void findPath(Node* head, int targetX, int targetY) {
    if (head == NULL) {
        return;
    }

    if (head->x == targetX && head->y == targetY) {
        printf("Path found!\n");
        return;
    }

    findPath(head->next, targetX, targetY);

    if (head->x + 1 == targetX) {
        printf("Move right\n");
    } else if (head->x - 1 == targetX) {
        printf("Move left\n");
    } else if (head->y + 1 == targetY) {
        printf("Move up\n");
    } else if (head->y - 1 == targetY) {
        printf("Move down\n");
    }
}

int main() {
    Node* head = NULL;
    insertNode(&head, 0, 0);
    insertNode(&head, 1, 0);
    insertNode(&head, 2, 0);
    insertNode(&head, 3, 0);
    insertNode(&head, 3, 1);
    insertNode(&head, 3, 2);
    insertNode(&head, 3, 3);

    findPath(head, 3, 3);

    return 0;
}