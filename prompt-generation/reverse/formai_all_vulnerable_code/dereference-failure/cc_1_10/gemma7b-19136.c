//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
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

void findRoute(Node* head, int x, int y) {
    Node* current = head;
    while (current) {
        if (current->x == x && current->y == y) {
            printf("Path found: (%d, %d) to (%d, %d)\n", current->x, current->y, x, y);
            return;
        }

        current = current->next;
    }

    printf("No path found.\n");
}

int main() {
    Node* head = NULL;
    insert(&head, 0, 0);
    insert(&head, 1, 0);
    insert(&head, 2, 0);
    insert(&head, 3, 0);
    insert(&head, 0, 1);
    insert(&head, 1, 1);
    insert(&head, 2, 1);
    insert(&head, 3, 1);

    findRoute(head, 2, 1);

    return 0;
}