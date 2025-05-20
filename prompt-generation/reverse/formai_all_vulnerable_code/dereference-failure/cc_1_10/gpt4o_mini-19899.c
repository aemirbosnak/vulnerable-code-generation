//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define the structure for an edge in the graph
typedef struct Edge {
    int src, dest, weight;
} Edge;

// Structure to represent a connected, directed graph
typedef struct Graph {
    int V, E; // V -> number of vertices, E -> number of edges
    Edge* edge; // dynamically allocated array of edges
} Graph;

// Function to create a graph with V vertices and E edges
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*)malloc(graph->E * sizeof(Edge));
    return graph;
}

// Function that finds the parent of a node
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Function to perform union of two subsets
void unionSet(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Function to check if the given edge creates a cycle or not
int isCycle(Graph* graph) {
    int* parent = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; ++i) {
        parent[i] = -1;
    }

    for (int i = 0; i < graph->E; ++i) {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);

        if (x == y)
            return 1; // Cycle detected

        unionSet(parent, x, y);
    }
    return 0; // No cycles
}

// Function to print the edges of the graph
void printGraph(Graph* graph) {
    printf("Edges in the graph:\n");
    for (int i = 0; i < graph->E; ++i) {
        printf("Edge from %d to %d with weight %d\n", 
               graph->edge[i].src, 
               graph->edge[i].dest, 
               graph->edge[i].weight);
    }
}

// Main function
int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    Graph* graph = createGraph(V, E);

    // Adding edges to the graph, with weights
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    printGraph(graph);
    
    // Check for cycle
    if (isCycle(graph))
        printf("The graph contains a cycle\n");
    else
        printf("The graph does not contain a cycle\n");

    // Free allocated memory
    free(graph->edge);
    free(graph);
    return 0;
}