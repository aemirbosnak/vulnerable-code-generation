//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 0x7FFFFFFF

struct Edge {
    int src;
    int dest;
    int weight;
};

void dijkstra(int** graph, int n, int start) {
    int dist[n];
    int visited[n];
    int i, j, k, u, v;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (k = 0; k < n - 1; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (graph[i][j] > 0 && dist[i]!= INF && dist[i] + graph[i][j] < dist[j]) {
                    dist[j] = dist[i] + graph[i][j];
                }
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int n, m, i, j, u, v, w;
    char ch;

    printf("Enter the number of nodes and edges: ");
    scanf("%d%d", &n, &m);

    int** graph = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }

    printf("Enter the edges with their weights (u v w):\n");
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int start;
    printf("Enter the starting node: ");
    scanf("%d", &start);

    dijkstra(graph, n, start);

    free(graph);
    return 0;
}