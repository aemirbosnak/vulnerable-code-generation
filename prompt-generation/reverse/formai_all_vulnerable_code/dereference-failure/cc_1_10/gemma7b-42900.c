//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

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

void findMazeRoute(Node* node) {
    if (node == NULL) {
        return;
    }

    printf("(%d, %d) ", node->x, node->y);

    findMazeRoute(node->next);
    findMazeRoute(node->next->next);
}

int main() {
    Node* head = createNode(0, 0);
    insertNode(head, 1, 1);
    insertNode(head, 2, 2);
    insertNode(head, 3, 3);
    insertNode(head, 4, 4);

    findMazeRoute(head);

    return 0;
}