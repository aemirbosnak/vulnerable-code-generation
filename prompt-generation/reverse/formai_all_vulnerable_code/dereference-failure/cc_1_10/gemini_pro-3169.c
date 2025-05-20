//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: high level of detail
#include <stdlib.h>
#include <stdio.h>

// A graph edge
typedef struct Edge {
    int src, dest, weight;
} Edge;

// A graph
typedef struct Graph {
    int V, E;  // Number of vertices and edges
    struct Edge* edge;  // Array of edges
} Graph;

// Create a graph with V vertices and E edges
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;

    graph->edge = (Edge*)malloc(graph->E * sizeof(Edge));

    return graph;
}

// A utility function to find the subset of an element i
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// A function to perform union of two subsets
void union_(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// The main function to check whether a given graph contains cycle or not
int isCycle(Graph* graph) {
    int* parent = (int*)malloc(graph->V * sizeof(int));

    // Initialize all subsets as single element sets
    for (int i = 0; i < graph->V; ++i)
        parent[i] = -1;

    // Iterate through all edges and check if there is a cycle
    for (int i = 0; i < graph->E; ++i) {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);

        if (x == y)
            return 1;

        union_(parent, x, y);
    }
    return 0;
}

// Driver program to test above functions
int main() {
    /* Let us create the following graph
        0
        | \
        |  \
        1---2 */
    int V = 3, E = 3;
    Graph* graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 1;

    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 1;

    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 1;

    if (isCycle(graph))
        printf("Graph contains cycle");
    else
        printf("Graph doesn't contain cycle");

    return 0;
}