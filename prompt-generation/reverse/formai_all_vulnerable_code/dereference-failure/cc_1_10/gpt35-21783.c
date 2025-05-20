//FormAI DATASET v1.0 Category: Graph representation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10 // maximum number of vertices
#define MAX_EDGES 15 // maximum number of edges

// struct to store edge information
typedef struct Edge {
    int src;
    int dest;
    int weight;
} Edge;

// struct to store graph information
typedef struct Graph {
    int numVertices;
    int numEdges;
    Edge edges[MAX_EDGES];
} Graph;

// function to create a new graph
Graph* createGraph(int numVertices, int numEdges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;

    // initialize edges to 0 weight
    for (int i = 0; i < numEdges; i++) {
        graph->edges[i].src = -1;
        graph->edges[i].dest = -1;
        graph->edges[i].weight = 0;
    }

    return graph;
}

// function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    int i;
    for (i = 0; i < graph->numEdges && graph->edges[i].src != -1; i++);
    if (i == graph->numEdges) {
        printf("Error: graph is full\n");
        return;
    }
    graph->edges[i].src = src;
    graph->edges[i].dest = dest;
    graph->edges[i].weight = weight;
}

// function to print the graph
void printGraph(Graph* graph) {
    printf("Graph:\n");
    printf("Vertices: %d\n", graph->numVertices);
    printf("Edges:\n");
    for (int i = 0; i < graph->numEdges && graph->edges[i].src != -1; i++) {
        printf("(%d,%d) weight=%d\n", graph->edges[i].src, graph->edges[i].dest, graph->edges[i].weight);
    }
}

int main() {
    // create a graph with 5 vertices and 7 edges
    Graph* graph = createGraph(5, 7);

    // add edges to the graph
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 2, 4, 6);
    addEdge(graph, 3, 4, 4);

    // print the graph
    printGraph(graph);

    // free the graph
    free(graph);

    return 0;
}