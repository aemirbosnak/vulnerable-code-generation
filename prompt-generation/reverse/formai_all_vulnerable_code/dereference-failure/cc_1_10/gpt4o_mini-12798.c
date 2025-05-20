//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// The tragic structure of our graph
typedef struct {
    int V; // Number of vertices
    int adj[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
} Graph;

// A function to create a graph
Graph* createGraph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = vertices;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            g->adj[i][j] = 0;
    return g;
}

// Function to add edge in the graph, like their fateful bond
void addEdge(Graph* g, int src, int dest) {
    g->adj[src][dest] = 1;
    g->adj[dest][src] = 1; // As love is a two-way street
}

// Function to check if it's safe to color a vertex
bool isSafe(int v, Graph* g, int color[], int c) {
    for (int i = 0; i < g->V; i++) {
        if (g->adj[v][i] && color[i] == c) {
            return false; // A forbidden love, shall not be!
        }
    }
    return true;
}

// Recursive function to solve the coloring problem
bool graphColoringUtil(Graph* g, int m, int color[], int v) {
    if (v == g->V) {
        return true; // All vertices have been colored, like a wedding gown
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, g, color, c)) {
            color[v] = c; // Coloring with a new shade
            if (graphColoringUtil(g, m, color, v + 1)) {
                return true;
            }
            color[v] = 0; // Backtracking, their love crossed paths no more
        }
    }
    return false; // Tragedy strikes, love unrequited
}

// Function to solve the graph coloring problem
void graphColoring(Graph* g, int m) {
    int* color = (int*)malloc(g->V * sizeof(int));
    for (int i = 0; i < g->V; i++)
        color[i] = 0; // Colors unclaimed, like rivals in love

    if (graphColoringUtil(g, m, color, 0) == false) {
        printf("Solution does not exist, alas!\n");
        return;
    }

    // Output the coloring of the graph, where love blooms
    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < g->V; i++)
        printf("Vertex %d ---> Color %d\n", i, color[i]);

    free(color);
}

// The epic tragedy unfolds
int main() {
    int vertices = 4; // The hearts entwined
    Graph* g = createGraph(vertices);

    // Edges representing the bonds of friendship and enmity
    addEdge(g, 0, 1); // Romeo <-> Mercutio
    addEdge(g, 0, 2); // Romeo <-> Tybalt
    addEdge(g, 1, 2); // Mercutio <-> Tybalt
    addEdge(g, 1, 3); // Mercutio <-> Juliet
    addEdge(g, 2, 3); // Tybalt <-> Juliet

    int m = 3; // Choices for romance, the colors of destiny

    graphColoring(g, m); // The climax of their fateful tale

    free(g);
    return 0;
}