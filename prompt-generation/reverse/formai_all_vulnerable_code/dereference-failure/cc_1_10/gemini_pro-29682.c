//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// The mind of the surrealist is a labyrinthine maze of abstract thoughts and eccentric ideas.
struct Graph {
    int V; // The number of vertices in the graph.
    int E; // The number of edges in the graph.
    int **adj; // The adjacency matrix representing the graph.
};

// A surreal journey through the graph.
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

// Adding edges to the surreal graph.
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1;
}

// Printing the surreal graph.
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// The main function where the surrealist journey begins.
int main() {
    // Creating a surreal graph with 5 vertices and 7 edges.
    struct Graph* graph = createGraph(5, 7);

    // Adding edges to the surreal graph.
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    // Printing the surreal graph.
    printGraph(graph);

    return 0;
}