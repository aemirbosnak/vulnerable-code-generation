//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

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

void printMaze(Node* node) {
    printf("(");
    printf("%d, %d)", node->x, node->y);
    printf(")\n");
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

    if (node->x - 1 >= 0 && node->y >= 0) {
        findRoute(createNode(node->x - 1, node->y), targetX, targetY);
    }

    if (node->x + 1 <= MAX_SIZE && node->y >= 0) {
        findRoute(createNode(node->x + 1, node->y), targetX, targetY);
    }

    if (node->x >= 0 && node->y - 1 <= MAX_SIZE) {
        findRoute(createNode(node->x, node->y - 1), targetX, targetY);
    }

    if (node->x >= 0 && node->y + 1 <= MAX_SIZE) {
        findRoute(createNode(node->x, node->y + 1), targetX, targetY);
    }
}

int main() {
    Node* head = createNode(0, 0);
    head->next = createNode(1, 1);
    head->next->next = createNode(2, 2);
    head->next->next->next = createNode(3, 3);

    findRoute(head, 3, 3);

    return 0;
}