//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void insert(Node** head, int x, int y) {
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

    if (head->x - targetX == 1) {
        printf("Move right\n");
    } else if (head->x - targetX == -1) {
        printf("Move left\n");
    } else if (head->y - targetY == 1) {
        printf("Move down\n");
    } else if (head->y - targetY == -1) {
        printf("Move up\n");
    }
}

int main() {
    Node* head = NULL;
    insert(&head, 0, 0);
    insert(&head, 1, 0);
    insert(&head, 2, 0);
    insert(&head, 3, 0);
    insert(&head, 3, 1);
    insert(&head, 3, 2);
    insert(&head, 3, 3);
    insert(&head, 2, 3);
    insert(&head, 1, 3);
    insert(&head, 0, 3);

    findPath(head, 2, 3);

    return 0;
}