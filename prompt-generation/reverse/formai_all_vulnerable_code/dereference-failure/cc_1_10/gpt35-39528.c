//FormAI DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

/* Structure for edge */
typedef struct {
    int src, dest, weight;
} edge;

/* Structure for graph */
typedef struct {
    int V, E;
    edge edges[MAX_VERTICES];
} graph;

/* Function to create a graph */
graph* createGraph(int V, int E) {
    graph* g = (graph*)malloc(sizeof(graph));
    g->V = V;
    g->E = E;
    return g;
}

/* Function to add an edge to the graph */
void addEdge(graph* g, int src, int dest, int weight) {
    int E = g->E;
    g->edges[E].src = src;
    g->edges[E].dest = dest;
    g->edges[E].weight = weight;
    g->E++;
}

/* Function to print the graph */
void printGraph(graph* g) {
    printf("Vertices: %d\nEdges:\n", g->V);
    for (int i=0; i<g->E; i++) {
        printf("%d--%d (%d)\n", g->edges[i].src, g->edges[i].dest, g->edges[i].weight);
    }
}

/* Main function */
int main() {
    int V = 5; // Number of vertices
    int E = 7; // Number of edges
    graph* g = createGraph(V, E); // Create graph
    
    // Add edges
    addEdge(g, 0, 1, 4);
    addEdge(g, 0, 2, 1);
    addEdge(g, 1, 2, 2);
    addEdge(g, 1, 3, 5);
    addEdge(g, 2, 3, 1);
    addEdge(g, 2, 4, 3);
    addEdge(g, 3, 4, 4);
    
    // Print graph
    printGraph(g);
    
    free(g); // Free memory
    
    return 0;
}