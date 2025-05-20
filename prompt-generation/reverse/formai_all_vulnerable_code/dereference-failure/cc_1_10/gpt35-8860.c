//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROWS 6
#define COLS 8

typedef struct node_s {
    int row, col;
    int dist, visited;
    struct node_s *parent;
} node_t;

node_t *graph[ROWS][COLS];

node_t *create_node(int row, int col) {
    node_t *node = (node_t *) malloc(sizeof(node_t));
    node->row = row;
    node->col = col;
    node->dist = INT_MAX;
    node->visited = 0;
    node->parent = NULL;
    return node;
}

void connect(node_t *a, node_t *b, int dist) {
    if (a && b) {
        if (!graph[a->row][a->col]) graph[a->row][a->col] = a;
        if (!graph[b->row][b->col]) graph[b->row][b->col] = b;
        if (a->dist > dist) {
            a->dist = dist;
            b->dist = dist;
            a->parent = b;
        }
    }
}

void dijkstra(node_t *start, node_t *end) {
    node_t *current = start;
    current->dist = 0;
    while (current && current != end) {
        current->visited = 1;
        int min_dist = INT_MAX;
        node_t *next = NULL;
        int r = current->row, c = current->col;
        if (r > 0 && !graph[r-1][c]->visited) {
            connect(graph[r][c], graph[r-1][c], 1);
            if (graph[r-1][c]->dist < min_dist) {
                min_dist = graph[r-1][c]->dist;
                next = graph[r-1][c];
            }
        }
        if (r < ROWS-1 && !graph[r+1][c]->visited) {
            connect(graph[r][c], graph[r+1][c], 1);
            if (graph[r+1][c]->dist < min_dist) {
                min_dist = graph[r+1][c]->dist;
                next = graph[r+1][c];
            }
        }
        if (c > 0 && !graph[r][c-1]->visited) {
            connect(graph[r][c], graph[r][c-1], 1);
            if (graph[r][c-1]->dist < min_dist) {
                min_dist = graph[r][c-1]->dist;
                next = graph[r][c-1];
            }
        }
        if (c < COLS-1 && !graph[r][c+1]->visited) {
            connect(graph[r][c], graph[r][c+1], 1);
            if (graph[r][c+1]->dist < min_dist) {
                min_dist = graph[r][c+1]->dist;
                next = graph[r][c+1];
            }
        }
        current = next;
    }
    if (end->parent) {
        printf("Path found: ");
        node_t *path = end;
        while (path) {
            printf("(%d,%d)", path->row, path->col);
            if (path->parent) printf(" -> ");
            path = path->parent;
        }
        printf("\n");
    }
    else {
        printf("No path found.\n");
    }
}

int main() {
    node_t *start = create_node(0,0);
    node_t *end = create_node(ROWS-1, COLS-1);
    dijkstra(start, end);
    return 0;
}