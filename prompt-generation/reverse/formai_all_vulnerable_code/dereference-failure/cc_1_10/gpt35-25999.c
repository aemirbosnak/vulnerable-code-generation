//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int distance[MAX_SIZE];
int previous[MAX_SIZE];
int visited[MAX_SIZE];

typedef struct node {
    int value;
    struct node *next;
} node_t;

node_t *graph[MAX_SIZE];

void add_edge(int x, int y) {
    node_t *p = malloc(sizeof(node_t));
    p->value = y;
    p->next = graph[x];
    graph[x] = p;
}

void dijkstra(int start) {
    memset(visited, 0, sizeof(visited));
    memset(distance, 0x3f, sizeof(distance));
    memset(previous, -1, sizeof(previous));
    distance[start] = 0;

    int u;
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        u = -1;
        int j;
        for (j = 0; j < MAX_SIZE; j++) {
            if (!visited[j] && (u == -1 || distance[j] < distance[u])) {
                u = j;
            }
        }
        if (distance[u] == 0x3f) break;

        visited[u] = 1;

        node_t *p = graph[u];
        while (p != NULL) {
            if (!visited[p->value] && distance[u] + 1 < distance[p->value]) {
                distance[p->value] = distance[u] + 1;
                previous[p->value] = u;
            }
            p = p->next;
        }
    }
}

int main() {

    add_edge(0,1);
    add_edge(1,2);
    add_edge(2,3);
    add_edge(2,4);
    add_edge(2,5);
    add_edge(1,4);
    add_edge(4,7);
    add_edge(4,8);
    add_edge(8,7);
    add_edge(8,9);
    add_edge(5,6);
    add_edge(6,9);

    dijkstra(0);

    int target = 9;

    printf("Path from 0 to %d:\n", target);

    int path[MAX_SIZE], n = 0;
    while (target != -1) {
        path[n++] = target;
        target = previous[target];
    }

    int i;
    for (i = n - 1; i >= 0; i--) {
        if (i == 0) {
            printf("%d.\n", path[i]);
        } else {
            printf("%d -> ", path[i]);
        }
    }

    return 0;
}