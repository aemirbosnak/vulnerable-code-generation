//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: multiplayer
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

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

void findPath(Node** head, int targetX, int targetY) {
    Node* current = *head;

    while (current) {
        if (current->x == targetX && current->y == targetY) {
            printf("Path found!\n");
            return;
        } else if (current->x > targetX || current->x < targetX) {
            current = current->next;
        } else if (current->y > targetY || current->y < targetY) {
            current = current->next;
        } else {
            insertNode(head, current->x - 1, current->y);
            insertNode(head, current->x + 1, current->y);
            insertNode(head, current->x, current->y - 1);
            insertNode(head, current->x, current->y + 1);
            current = current->next;
        }
    }

    printf("No path found.\n");
}

int main() {
    Node* head = NULL;
    insertNode(&head, 0, 0);
    insertNode(&head, 1, 0);
    insertNode(&head, 2, 0);
    insertNode(&head, 2, 1);
    insertNode(&head, 2, 2);

    findPath(&head, 2, 2);

    return 0;
}