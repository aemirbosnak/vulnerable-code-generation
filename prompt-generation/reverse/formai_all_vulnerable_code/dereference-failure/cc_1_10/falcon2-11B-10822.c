//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int x;
    int y;
    struct node* next;
} node;

node* createNode(int x, int y) {
    node* n = (node*)malloc(sizeof(node));
    n->x = x;
    n->y = y;
    n->next = NULL;
    return n;
}

void addEdge(node* n, int x, int y) {
    node* e = createNode(x, y);
    e->next = n->next;
    n->next = e;
}

bool isPath(node* start, node* end) {
    node* current = start;
    while (current!= end) {
        if (current->next == NULL) {
            return false;
        }
        current = current->next;
    }
    return true;
}

int main() {
    node* start = createNode(0, 0);
    addEdge(start, 1, 1);
    addEdge(start, 2, 1);
    addEdge(start, 3, 2);
    addEdge(start, 4, 2);
    addEdge(start, 5, 3);
    addEdge(start, 6, 3);

    node* goal = createNode(5, 5);
    addEdge(goal, 6, 5);
    addEdge(goal, 7, 4);
    addEdge(goal, 8, 4);
    addEdge(goal, 9, 3);

    node* current = start;
    while (current!= goal) {
        if (current->next == NULL) {
            printf("No path found.\n");
            return 0;
        }
        current = current->next;
    }
    printf("Path found.\n");
    return 0;
}