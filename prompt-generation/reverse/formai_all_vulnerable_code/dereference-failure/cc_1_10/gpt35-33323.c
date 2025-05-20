//FormAI DATASET v1.0 Category: Graph representation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10 // Maximum number of vertices allowed

struct Graph {
    int V; // number of vertices in the graph
    int E; // number of edges in the graph
    int adj[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix
};

// function to create a new graph
struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));

    graph->V = 0;
    graph->E = 0;

    int i, j;
    for (i=0; i<MAX_VERTICES; i++)
        for (j=0; j<MAX_VERTICES; j++)
            graph->adj[i][j] = 0; // Initially there are no edges

    return graph;
}

// function to add an edge to the graph
void addEdge(struct Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
    graph->E++;
}

// function to print the graph
void printGraph(struct Graph* graph) {
    int i, j;
    printf("Vertices: %d, Edges: %d\n", graph->V, graph->E);

    for (i=0; i<graph->V; i++) {
        for (j=0; j<graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph* graph = createGraph();

    // adding vertices and edges
    graph->V = 5;
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // printing the graph
    printGraph(graph);

    return 0;
}