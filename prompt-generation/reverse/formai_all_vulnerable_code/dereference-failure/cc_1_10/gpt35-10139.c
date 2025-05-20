//FormAI DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// structure to represent a graph
struct Graph {
    int V; // number of vertices
    int E; // number of edges
    int **adj; // matrix pointer to store adjacency matrix
};

// function to create a new graph
struct Graph *createGraph(int V, int E) {
    int i, j;
    struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph)); // allocate memory for graph
    if (graph == NULL) {
        printf("Memory allocation failed for graph\n");
        return NULL;
    }
    graph->V = V;
    graph->E = E;
    graph->adj = (int **) malloc(V * sizeof(int *)); // allocate memory for adjacency matrix
    if (graph->adj == NULL) {
        printf("Memory allocation failed for adjacency matrix\n");
        return NULL;
    }
    for (i = 0; i < V; i++) {
        graph->adj[i] = (int *) malloc(V * sizeof(int));
        if (graph->adj[i] == NULL) {
            printf("Memory allocation failed for adjacency matrix row %d\n", i);
            return NULL;
        }
        for (j = 0; j < V; j++) {
            graph->adj[i][j] = 0; // initialize all elements to 0
        }
    }
    return graph;
}

// function to add an edge to the graph
void addEdge(struct Graph *graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

// function to print the graph
void printGraph(struct Graph *graph) {
    int i, j;
    printf("\nAdjacency matrix representation of the graph:\n\n");
    for (i = 0; i < graph->V; i++) {
        for (j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    struct Graph *graph = createGraph(4, 3); // create a new graph with 4 vertices and 3 edges
    if (graph == NULL) {
        printf("Could not create graph\n");
        return -1;
    }
    addEdge(graph, 0, 1); // add an edge between vertex 0 and vertex 1
    addEdge(graph, 0, 2); // add an edge between vertex 0 and vertex 2
    addEdge(graph, 1, 3); // add an edge between vertex 1 and vertex 3
    printGraph(graph); // print the graph
    return 0;
}