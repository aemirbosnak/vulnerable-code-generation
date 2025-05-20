//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define INF 99999

typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                graph->adjMatrix[i][j] = 0;
            } else {
                graph->adjMatrix[i][j] = INF;
            }
        }
    }
    return graph;
}

void addEdge(Graph* graph, int start, int end, int weight) {
    graph->adjMatrix[start][end] = weight;
    graph->adjMatrix[end][start] = weight; // For undirected graph
}

void printGraph(Graph* graph) {
    printf("Graph Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjMatrix[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", graph->adjMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

void dijkstra(Graph* graph, int startVertex) {
    int distance[MAX_VERTICES];
    int visited[MAX_VERTICES];
    
    for (int i = 0; i < graph->numVertices; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }
    distance[startVertex] = 0;

    for (int count = 0; count < graph->numVertices - 1; count++) {
        int u = -1;
        for (int i = 0; i < graph->numVertices; i++) {
            if (!visited[i] && (u == -1 || distance[i] < distance[u])) {
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < graph->numVertices; v++) {
            if (!visited[v] && graph->adjMatrix[u][v] != INF) {
                int newDist = distance[u] + graph->adjMatrix[u][v];
                if (newDist < distance[v]) {
                    distance[v] = newDist;
                }
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", startVertex);
    for (int i = 0; i < graph->numVertices; i++) {
        if (distance[i] == INF) {
            printf("Distance to vertex %d: INF\n", i);
        } else {
            printf("Distance to vertex %d: %d\n", i, distance[i]);
        }
    }
}

int main() {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int start, end, weight;
        printf("Enter start vertex, end vertex and weight: ");
        scanf("%d %d %d", &start, &end, &weight);
        addEdge(graph, start, end, weight);
    }

    printGraph(graph);

    int startVertex;
    printf("Enter the starting vertex for Dijkstra's algorithm: ");
    scanf("%d", &startVertex);

    dijkstra(graph, startVertex);

    free(graph);
    return 0;
}