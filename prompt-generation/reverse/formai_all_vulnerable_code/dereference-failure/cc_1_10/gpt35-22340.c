//FormAI DATASET v1.0 Category: Graph representation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// Graph structure
struct Graph {
    int V; // number of vertices
    int E; // number of edges
    int **adj; // adjacency matrix
};

// createGraph function to initialize a graph
struct Graph *createGraph(int V, int E) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->adj = malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = malloc(V * sizeof(int));
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

// adding edges to the graph
void addEdge(struct Graph *graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

// printing the graph
void printGraph(struct Graph *graph) {
    printf("\nGraph Representation:\n\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// main function
int main() {
    int V, E, u, v;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &E);
    struct Graph *graph = createGraph(V, E);
    for (int i = 0; i < E; i++) {
        printf("Enter the vertices of edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }
    printGraph(graph);
    return 0;
}