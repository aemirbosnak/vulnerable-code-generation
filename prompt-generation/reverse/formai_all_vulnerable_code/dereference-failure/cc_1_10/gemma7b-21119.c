//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node* head, int x, int y) {
    Node* newNode = createNode(x, y);
    if (head == NULL) {
        head = newNode;
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
        } else if (current->x > targetX || current->y > targetY) {
            break;
        } else {
            insertNode(current, current->x + 1, current->y);
            insertNode(current, current->x - 1, current->y);
            insertNode(current, current->x, current->y + 1);
            insertNode(current, current->x, current->y - 1);
        }
        current = current->next;
    }
    printf("No path found.\n");
}

int main() {
    Node* head = NULL;
    insertNode(head, 0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 2, 1);
    insertNode(head, 2, 2);
    insertNode(head, 3, 2);

    findPath(head, 3, 2);

    return 0;
}