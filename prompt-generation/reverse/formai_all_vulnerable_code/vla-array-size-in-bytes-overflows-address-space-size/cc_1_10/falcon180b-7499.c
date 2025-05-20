//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_V 100

struct Edge {
    int to;
    int cost;
};

void dijkstra(int start, int end, struct Edge graph[MAX_V][MAX_V], int n) {
    int dist[n];
    int visited[n];
    int prev[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        prev[i] = -1;
    }

    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < INF) {
                u = j;
                break;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int new_dist = dist[u] + graph[u][v].cost;

                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    prev[v] = u;
                }
            }
        }
    }

    printf("Shortest path: ");
    int v = end;
    while (v!= -1) {
        printf("%d ", v);
        v = prev[v];
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Edge graph[MAX_V][MAX_V];

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v].cost = w;
        graph[v][u].cost = w;
    }

    dijkstra(0, n - 1, graph, n);

    return 0;
}