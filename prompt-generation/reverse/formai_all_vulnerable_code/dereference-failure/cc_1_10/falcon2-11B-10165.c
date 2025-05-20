//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int x;
    int y;
    int g;
    int h;
    bool visited;
    struct node* next;
} node;

void bfs(node** start, node** goal) {
    node* q = NULL;
    node* current = NULL;

    q = start;
    current = start;

    while (q!= NULL && current!= goal) {
        printf("(%d, %d) ", current->x, current->y);
        current = q;
        q = q->next;
        current->visited = true;
    }

    if (q == NULL) {
        printf("No path found\n");
    } else {
        printf("(%d, %d) ", q->x, q->y);
    }
}

int main() {
    int sizeX = 10;
    int sizeY = 10;
    int startX = 0;
    int startY = 0;
    int goalX = 5;
    int goalY = 5;

    node* start = NULL;
    node* goal = NULL;

    for (int i = 0; i < sizeY; i++) {
        start = (node*)malloc(sizeof(node));
        start->x = startX;
        start->y = i;
        start->g = 0;
        start->h = 0;
        start->visited = false;
        start->next = NULL;

        if (i == startY) {
            start->next = goal;
        } else {
            start->next = start;
        }
    }

    for (int i = 0; i < sizeY; i++) {
        goal = (node*)malloc(sizeof(node));
        goal->x = goalX;
        goal->y = i;
        goal->g = sizeX * sizeY;
        goal->h = 0;
        goal->visited = false;
        goal->next = NULL;
    }

    bfs(&start, &goal);

    return 0;
}