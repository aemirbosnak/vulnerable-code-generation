//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void initialize(Node** head) {
    *head = NULL;
}

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

void findRoute(Node* head, int targetX, int targetY) {
    Node* current = head;
    while (current) {
        if (current->x == targetX && current->y == targetY) {
            printf("Path found!\n");
            return;
        } else if (current->x < targetX && current->y < targetY) {
            insert(head, current->x + 1, current->y);
        } else if (current->x > targetX && current->y > targetY) {
            insert(head, current->x - 1, current->y - 1);
        } else if (current->x < targetX && current->y > targetY) {
            insert(head, current->x + 1, current->y - 1);
        }
        current = current->next;
    }

    printf("No path found.\n");
}

int main() {
    Node* head = NULL;
    initialize(&head);

    insert(head, 0, 0);
    insert(head, 1, 0);
    insert(head, 2, 0);
    insert(head, 3, 0);
    insert(head, 4, 0);

    insert(head, 0, 1);
    insert(head, 1, 1);
    insert(head, 2, 1);
    insert(head, 3, 1);
    insert(head, 4, 1);

    findRoute(head, 2, 2);

    return 0;
}