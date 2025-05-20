//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void initialize(Node** head) {
    *head = NULL;
}

void insert(Node** head, int x, int y) {
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

int distance(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

int findPath(int x, int y, Node** head) {
    if (*head == NULL) {
        return -1;
    }

    Node* current = *head;
    while (current) {
        if (current->x == x && current->y == y) {
            return 0;
        }

        int d = distance(x, y, current->x, current->y);
        if (d < findPath(x, y, &current->next)) {
            current = current->next;
        }
    }

    return -1;
}

int main() {
    Node* head = NULL;
    initialize(&head);

    insert( &head, 0, 0);
    insert( &head, 1, 0);
    insert( &head, 2, 0);
    insert( &head, 3, 0);
    insert( &head, 4, 0);
    insert( &head, 5, 0);
    insert( &head, 0, 1);
    insert( &head, 1, 1);
    insert( &head, 2, 1);
    insert( &head, 3, 1);
    insert( &head, 4, 1);
    insert( &head, 5, 1);

    int path = findPath(2, 2, &head);

    if (path == -1) {
        printf("No path found.\n");
    } else {
        printf("Path found: %d\n", path);
    }

    return 0;
}