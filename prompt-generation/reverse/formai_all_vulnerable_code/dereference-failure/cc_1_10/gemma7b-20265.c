//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
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

void findRoute(Node* node, int targetX, int targetY) {
    if (node == NULL) {
        return;
    }
    if (node->x == targetX && node->y == targetY) {
        printf("Path found!\n");
        return;
    }
    findRoute(node->next, targetX, targetY);
    if (node->x - targetX > 0) {
        printf("Move left.\n");
    } else if (node->x - targetX < 0) {
        printf("Move right.\n");
    }
    if (node->y - targetY > 0) {
        printf("Move down.\n");
    } else if (node->y - targetY < 0) {
        printf("Move up.\n");
    }
}

int main() {
    Node* head = NULL;
    insertNode(head, 0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 3, 0);
    insertNode(head, 3, 1);
    insertNode(head, 3, 2);
    insertNode(head, 3, 3);

    findRoute(head, 3, 3);

    return 0;
}