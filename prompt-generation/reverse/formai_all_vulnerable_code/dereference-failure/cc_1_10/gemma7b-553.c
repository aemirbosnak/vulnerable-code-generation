//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void initialize(Node* head) {
    head = (Node*)malloc(sizeof(Node));
    head->x = -1;
    head->y = -1;
    head->next = NULL;
}

void insert(Node* head, int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (head->next == NULL) {
        head->next = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void findPath(Node* head, int targetX, int targetY) {
    Node* current = head;
    while (current) {
        if (current->x == targetX && current->y == targetY) {
            printf("Path found!\n");
            return;
        }

        current = current->next;
    }

    printf("Path not found.\n");
}

int main() {
    Node* head = NULL;
    initialize(head);

    insert(head, 0, 0);
    insert(head, 1, 0);
    insert(head, 2, 0);
    insert(head, 3, 0);
    insert(head, 4, 0);
    insert(head, 0, 1);
    insert(head, 1, 1);
    insert(head, 2, 1);
    insert(head, 3, 1);
    insert(head, 0, 2);
    insert(head, 1, 2);
    insert(head, 2, 2);
    insert(head, 3, 2);

    findPath(head, 4, 2);

    return 0;
}