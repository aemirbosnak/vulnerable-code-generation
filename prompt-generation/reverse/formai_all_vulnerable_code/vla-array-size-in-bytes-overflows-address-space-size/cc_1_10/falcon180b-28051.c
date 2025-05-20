//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100
#define INF INT_MAX

typedef struct {
    int x;
    int y;
} Node;

Node graph[MAX_NODES];
int n;

void readGraph() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the coordinates of the nodes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &graph[i].x, &graph[i].y);
    }
}

void dijkstra(int start) {
    int dist[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        int minDist = INF;
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u].x!= graph[v].x && graph[u].y!= graph[v].y) {
                int newDist = dist[u] + abs(graph[u].x - graph[v].x) + abs(graph[u].y - graph[v].y);

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                }
            }
        }
    }

    printf("Node\tDistance from Start\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

int main() {
    readGraph();
    int start;

    printf("Enter the starting node: ");
    scanf("%d", &start);

    dijkstra(start);

    return 0;
}