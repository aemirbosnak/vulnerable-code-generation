//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
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
    newNode->next = node->next;
    node->next = newNode;
}

void findPath(Node* start, Node* end) {
    Node* current = start;
    while (current) {
        if (current->x == end->x && current->y == end->y) {
            printf("Path found!");
            return;
        }
        insertNode(current, current->x + 1, current->y);
        insertNode(current, current->x - 1, current->y);
        insertNode(current, current->x, current->y + 1);
        insertNode(current, current->x, current->y - 1);
        current = current->next;
    }
    printf("No path found.");
}

int main() {
    Node* start = createNode(0, 0);
    Node* end = createNode(5, 5);

    insertNode(start, 1, 0);
    insertNode(start, 2, 0);
    insertNode(start, 3, 0);
    insertNode(start, 3, 1);
    insertNode(start, 3, 2);
    insertNode(start, 3, 3);
    insertNode(start, 3, 4);
    insertNode(start, 4, 4);
    insertNode(start, 5, 4);

    findPath(start, end);

    return 0;
}