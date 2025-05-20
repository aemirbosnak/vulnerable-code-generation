//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

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

int distance(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

void findPath(Node* head, int targetX, int targetY) {
    Node* current = head;
    while (current) {
        if (distance(current->x, current->y, targetX, targetY) <= MAX) {
            printf("Path found! Distance: %d\n", distance(current->x, current->y, targetX, targetY));
            return;
        }
        current = current->next;
    }
    printf("No path found.\n");
}

int main() {
    Node* head = NULL;
    insert(&head, 0, 0);
    insert(&head, 1, 1);
    insert(&head, 2, 2);
    insert(&head, 3, 3);
    insert(&head, 4, 4);

    findPath(head, 3, 3);

    return 0;
}