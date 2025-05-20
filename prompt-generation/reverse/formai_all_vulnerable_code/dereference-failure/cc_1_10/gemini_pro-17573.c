//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: realistic
// Graph Coloring Problem
// Given a graph of n vertices and m edges, the task is to assign colors to the vertices such that no two adjacent vertices have the same color.
// The following program uses a greedy algorithm to solve the problem.

#include <stdio.h>
#include <stdlib.h>

// A structure to represent a graph
struct Graph {
    int V;     // Number of vertices
    int E;     // Number of edges
    int **adj; // Adjacency matrix
};

// A utility function to create a new graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

// A utility function to add an edge to a graph
void addEdge(struct Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

// A utility function to print the adjacency matrix of a graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// A utility function to check if two vertices are adjacent
int isAdjacent(struct Graph* graph, int u, int v) {
    return graph->adj[u][v] == 1;
}

// A utility function to find the degree of a vertex
int degree(struct Graph* graph, int v) {
    int deg = 0;
    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v][i] == 1) {
            deg++;
        }
    }
    return deg;
}

// A utility function to find the minimum degree vertex
int minDegreeVertex(struct Graph* graph) {
    int min_deg = graph->V;
    int min_deg_vertex = -1;
    for (int i = 0; i < graph->V; i++) {
        int deg = degree(graph, i);
        if (deg < min_deg) {
            min_deg = deg;
            min_deg_vertex = i;
        }
    }
    return min_deg_vertex;
}

// A function to greedy color a graph
int greedyColoring(struct Graph* graph) {
    int colors[graph->V];  // Colors assigned to vertices
    int num_colors = 0;  // Number of colors used

    // Initialize all vertices as unassigned
    for (int i = 0; i < graph->V; i++) {
        colors[i] = -1;
    }

    // A temporary array to store the available colors for a vertex
    int available[graph->V];

    // Assign a color to the first vertex
    colors[0] = 0;

    // Iterate over the remaining vertices
    for (int i = 1; i < graph->V; i++) {
        // Get the available colors for the current vertex
        for (int j = 0; j < graph->V; j++) {
            available[j] = 1;
        }

        // Iterate over the adjacent vertices of the current vertex
        for (int j = 0; j < graph->V; j++) {
            if (isAdjacent(graph, i, j) && colors[j] != -1) {
                available[colors[j]] = 0;
            }
        }

        // Find the first available color for the current vertex
        int color = -1;
        for (int j = 0; j < graph->V; j++) {
            if (available[j] == 1) {
                color = j;
                break;
            }
        }

        // Assign the color to the current vertex
        colors[i] = color;

        // Increment the number of colors used
        num_colors++;
    }

    // Print the coloring
    printf("The following coloring uses %d colors:\n", num_colors);
    for (int i = 0; i < graph->V; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }

    return num_colors;
}

// A function to test the greedy coloring algorithm
int main() {
    // Create a graph
    struct Graph* graph = createGraph(5, 6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printf("The graph is:\n");
    printGraph(graph);

    // Greedy color the graph
    int num_colors = greedyColoring(graph);

    // Print the number of colors used
    printf("The number of colors used is: %d\n", num_colors);

    return 0;
}