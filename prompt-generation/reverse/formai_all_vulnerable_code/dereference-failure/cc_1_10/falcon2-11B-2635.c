//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Node;

typedef struct {
    Node* nodes;
} Graph;

typedef struct {
    Graph* graph;
    int* path;
    int size;
} BFS;

void run(Graph* graph, int start, int end) {
    BFS bfs;
    bfs.graph = graph;
    bfs.path = malloc(bfs.graph->nodes[end].y * sizeof(int));
    bfs.size = bfs.graph->nodes[end].y;
    for (int i = 0; i < bfs.size; i++) {
        bfs.path[i] = -1;
    }
    int q[100];
    int front = 0;
    int rear = 0;
    q[rear++] = start;
    bfs.path[0] = start;
    while (front < rear) {
        int cur = q[front++];
        if (cur == end) {
            while (front > rear) {
                printf("%d ", bfs.path[rear++]);
            }
            return;
        }
        for (int i = 0; i < bfs.graph->nodes[cur].y; i++) {
            if (bfs.path[i]!= -1) {
                continue;
            }
            q[rear++] = bfs.graph->nodes[cur].x + bfs.graph->nodes[cur].y * i;
            bfs.path[i] = cur;
        }
    }
}

int main() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    Node* nodes[] = {
        {0, 0},
        {1, 0},
        {0, 1},
        {1, 1}
    };
    graph->nodes = nodes;
    int start = 0;
    int end = 2;
    run(graph, start, end);
    free(graph);
    return 0;
}