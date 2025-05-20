//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define INF 9999

typedef struct {
    int name;
    int x, y;
    int cost;
} Node;

void addEdge(Node graph[MAX_NODES], int u, int v, int cost) {
    graph[u].cost = cost;
    graph[v].cost = cost;
}

void dijkstra(Node graph[MAX_NODES], int startNode) {
    int n = MAX_NODES;
    int dist[MAX_NODES];
    int visited[MAX_NODES] = {0};
    int i, j, u, minDist;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
    }

    dist[startNode] = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            if (visited[j] == 0 && dist[j] > dist[i]) {
                dist[j] = dist[i] + graph[i].cost;
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

int main() {
    Node graph[MAX_NODES];
    int i, j, n, u, v, cost;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the name of node %d: ", i + 1);
        scanf("%d", &graph[i].name);
        printf("Enter the x coordinate of node %d: ", i + 1);
        scanf("%d", &graph[i].x);
        printf("Enter the y coordinate of node %d: ", i + 1);
        scanf("%d", &graph[i].y);
    }

    printf("Enter the edges and their costs in the format 'node1 node2 cost':\n");
    for (i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &u, &v, &cost);
        addEdge(graph, u, v, cost);
    }

    int startNode;
    printf("Enter the starting node: ");
    scanf("%d", &startNode);

    dijkstra(graph, startNode);

    return 0;
}