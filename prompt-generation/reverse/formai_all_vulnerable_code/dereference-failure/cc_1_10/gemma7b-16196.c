//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: standalone
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

void insertNode(Node* node, int x, int y) {
    Node* newNode = createNode(x, y);
    if (node == NULL) {
        node = newNode;
    } else {
        node->next = newNode;
        node = newNode;
    }
}

void findMazeRoute(Node* node, int targetX, int targetY) {
    if (node == NULL) {
        return;
    }

    if (node->x == targetX && node->y == targetY) {
        printf("Path found!\n");
        return;
    }

    insertNode(node, node->x + 1, node->y);
    insertNode(node, node->x - 1, node->y);
    insertNode(node, node->x, node->y + 1);
    insertNode(node, node->x, node->y - 1);

    findMazeRoute(node->next, targetX, targetY);
}

int main() {
    Node* head = NULL;
    insertNode(head, 0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 2, 1);
    insertNode(head, 2, 2);
    insertNode(head, 3, 2);

    findMazeRoute(head, 3, 2);

    return 0;
}