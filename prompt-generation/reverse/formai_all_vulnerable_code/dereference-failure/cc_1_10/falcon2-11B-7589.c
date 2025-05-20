//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_ROWS 50
#define MAX_COLS 50

struct Node {
    int x;
    int y;
    int parent;
    bool visited;
    int height;
};

typedef struct Node Node;

Node *initializeNode(Node *node) {
    node->x = 0;
    node->y = 0;
    node->parent = -1;
    node->visited = false;
    node->height = INT_MAX;
    return node;
}

void printNode(Node *node) {
    printf("(x, y) = (%d, %d)\n", node->x, node->y);
    printf("parent = %d\n", node->parent);
    printf("visited = %s\n", node->visited? "true" : "false");
    printf("height = %d\n", node->height);
}

void printPath(Node *start, Node *end) {
    Node *current = end;
    while (current!= start) {
        printNode(current);
        current = current->parent;
    }
}

Node *findShortestPath(Node *start, Node *end) {
    if (start->height < end->height) {
        Node *temp = start;
        start = end;
        end = temp;
    }

    if (start->height == end->height) {
        start->height = end->height + 1;
    } else {
        return start;
    }

    Node *neighbor;
    Node *current = start;
    while (true) {
        if (current->visited) {
            current = current->parent;
            continue;
        }

        current->visited = true;
        current->parent = neighbor;

        neighbor = findShortestPath(neighbor, end);

        if (neighbor == end) {
            break;
        }

        current = neighbor;
    }

    return neighbor;
}

int main() {
    Node *start = initializeNode(NULL);
    Node *end = initializeNode(NULL);
    start->x = 0;
    start->y = 0;
    end->x = 4;
    end->y = 4;

    Node *node = findShortestPath(start, end);
    printPath(start, node);
    printNode(node);

    return 0;
}