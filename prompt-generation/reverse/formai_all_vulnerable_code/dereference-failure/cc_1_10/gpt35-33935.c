//FormAI DATASET v1.0 Category: Graph representation ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

// Edge structure
struct Edge {
    int src, dest;
};

// Graph structure
struct Graph {
    int V, E;
    struct Edge* edges;
};

// Function to create a Graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*) malloc(sizeof(struct Edge) * E);
    return graph;
}

// Function to print the Graph
void printGraph(struct Graph* graph) {
    printf("The Graph has %d vertices and %d edges.\n", graph->V, graph->E);
    printf("The edges in the Graph are:\n");
    for(int i=0; i<graph->E; i++)
        printf("%d -- %d\n", graph->edges[i].src, graph->edges[i].dest);
}

// Main function
int main() {
    int V = 5, E = 6;
    struct Graph* graph = createGraph(V, E);

    // Initialize the edges
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;

    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;

    graph->edges[2].src = 1;
    graph->edges[2].dest = 2;

    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;

    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;

    graph->edges[5].src = 3;
    graph->edges[5].dest = 4;

    // Print the Graph
    printGraph(graph);

    return 0;
}