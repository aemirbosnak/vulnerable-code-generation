//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void initialize(Node** head, int x, int y) {
    *head = (Node*)malloc(sizeof(Node));
    (*head)->x = x;
    (*head)->y = y;
    (*head)->next = NULL;
}

void addNode(Node** head, int x, int y) {
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

void findPath(Node* head, int targetX, int targetY) {
    Node* current = head;
    while (current) {
        if (current->x == targetX && current->y == targetY) {
            printf("Path found!\n");
            return;
        } else if (current->x > targetX || current->y > targetY) {
            break;
        } else {
            addNode(head, current->x - 1, current->y);
            addNode(head, current->x + 1, current->y);
            addNode(head, current->x, current->y - 1);
            addNode(head, current->x, current->y + 1);
            current = current->next;
        }
    }

    printf("No path found.\n");
}

int main() {
    Node* head = NULL;
    initialize(&head, 0, 0);
    addNode(head, 1, 1);
    addNode(head, 2, 2);
    addNode(head, 3, 3);
    addNode(head, 4, 4);
    addNode(head, 5, 5);

    findPath(head, 4, 4);

    return 0;
}