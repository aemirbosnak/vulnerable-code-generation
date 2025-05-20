//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* insert(Node* head, int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void findRoute(Node* head, int targetX, int targetY) {
    Node* current = head;
    while (current) {
        if (current->x == targetX && current->y == targetY) {
            printf("Path found!\n");
            return;
        }

        current = current->next;
    }

    printf("No path found.\n");
}

int main() {
    Node* head = insert(NULL, 0, 0);
    insert(head, 1, 1);
    insert(head, 2, 2);
    insert(head, 3, 3);
    insert(head, 4, 4);

    findRoute(head, 3, 3);

    return 0;
}