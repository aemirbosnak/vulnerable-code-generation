//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Edge {
    int dest;
    int weight;
} Edge;

typedef struct Graph {
    int V;
    int E;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void addEdge(Graph *graph, int src, int dest, int weight) {
    graph->adjMatrix[src][dest] = weight;
    graph->adjMatrix[dest][src] = weight;
}

bool isVisited(int *visited, int vertex) {
    return visited[vertex] == 1;
}

int minDistance(Graph *graph, int *dist, int *visited) {
    int min = INT_MAX, index;

    for (int i = 0; i < graph->V; ++i) {
        if (!isVisited(visited, i) && dist[i] <= min) {
            min = dist[i];
            index = i;
        }
    }

    return index;
}

void dijkstra(Graph *graph, int src) {
    int *dist = calloc(graph->V, sizeof(int));
    int *visited = calloc(graph->V, sizeof(int));

    for (int i = 0; i < graph->V; ++i) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    int s = src;

    while (s != -1) {
        int u = s;

        for (int i = 0; i < graph->V; ++i) {
            int alt = dist[u] + graph->adjMatrix[u][i];

            if (alt < dist[i]) {
                dist[i] = alt;
                visited[i] = 1;
            }
        }

        s = minDistance(graph, dist, visited);
    }

    free(dist);
    free(visited);
}

int main() {
    Graph graph = { .V = 5, .E = 8 };

    addEdge(&graph, 0, 1, 4);
    addEdge(&graph, 0, 4, 3);
    addEdge(&graph, 1, 2, 2);
    addEdge(&graph, 1, 4, 1);
    addEdge(&graph, 2, 3, 6);
    addEdge(&graph, 2, 4, 2);
    addEdge(&graph, 3, 4, 5);

    dijkstra(&graph, 0);

    printf("Shortest distances from node 0 to all other nodes:\n");
    for (int i = 0; i < graph.V; ++i) {
        printf("Node %d : %d\n", i, graph.adjMatrix[0][i]);
    }

    return 0;
}