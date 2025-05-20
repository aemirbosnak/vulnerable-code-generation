//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct to represent an edge of a graph.
struct Edge {
    int src;
    int dest;
};

// Define a struct to represent a graph.
struct Graph {
    int V; // number of vertices
    int E; // number of edges
    struct Edge* edges;
};

// Function to check if the given color is safe for the given vertex.
bool isSafe(int v, struct Graph* graph, int color[], int c) {
    for (int i = 0; i < graph->E; ++i) {
        if (graph->edges[i].src == v) {
            if (color[graph->edges[i].dest] == c) {
                return false;
            }
        }
        if (graph->edges[i].dest == v) {
            if (color[graph->edges[i].src] == c) {
                return false;
            }
        }
    }

    return true;
}

// Function to recursive function to solve graph coloring.
bool graphColoringHelper(struct Graph* graph, int m, int color[], int v) {
    if (v == graph->V) {
        return true; // all vertices successfully colored!
    }

    // Try different colors for vertex v.
    for (int c = 1; c <= m; ++c) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c; // set color for vertex v
            if (graphColoringHelper(graph, m, color, v + 1)) {
                return true;
            }
            color[v] = 0; // backtrack
        }
    }

    return false; // no solution found
}

// Function to solve graph coloring problem.
bool graphColoring(struct Graph* graph, int m, int* color) {
    // Initialize all colors as 0 (unassigned)
    for (int i = 0; i < graph->V; ++i) {
        color[i] = 0;
    }

    // Start with the first vertex
    return graphColoringHelper(graph, m, color, 0);
}

// The driver code
int main() {
    // Create a graph with 4 vertices and 5 edges
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = 4;
    graph->E = 5;
    graph->edges = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
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

    int m = 3; // Number of colors
    int* color = (int*)malloc(graph->V * sizeof(int));

    if (graphColoring(graph, m, color)) {
        printf("Solution exists:\n");
        for (int i = 0; i < graph->V; ++i) {
            printf("Vertex %d --> Color %d\n", i, color[i]);
        }
    } else {
        printf("Solution does not exist!");
    }

    free(color);
    free(graph->edges);
    free(graph);

    return 0;
}