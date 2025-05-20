//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
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

void findPath(Node* head, int targetX, int targetY) {
    Node* current = head;
    while (current) {
        if (current->x == targetX && current->y == targetY) {
            printf("Path found!\n");
            return;
        } else if (current->x < targetX && current->y < targetY) {
            current = current->next;
        } else if (current->x > targetX && current->y > targetY) {
            current = current->next;
        } else if (current->x < targetX && current->y > targetY) {
            current = current->next;
        } else if (current->x > targetX && current->y < targetY) {
            current = current->next;
        }
    }

    printf("Path not found.\n");
}

int main() {
    Node* head = insert(NULL, 0, 0);
    insert(head, 1, 1);
    insert(head, 2, 2);
    insert(head, 3, 3);
    insert(head, 4, 4);
    insert(head, 5, 5);

    findPath(head, 4, 4);

    return 0;
}