//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define NO_COLOR -1

typedef struct {
    int adj[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Function to initialize a graph
void initializeGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0; // Initialize adjacency matrix to 0
        }
    }
}

// Function to add an edge to the graph
void addEdge(Graph* g, int src, int dest) {
    g->adj[src][dest] = 1;
    g->adj[dest][src] = 1; // Because the graph is undirected
}

// Function to print the graph in adjacency matrix form
void printGraph(Graph* g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the color can be assigned to a vertex
int canColor(Graph* g, int vertex, int color, int* colors) {
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adj[vertex][i] == 1 && colors[i] == color) {
            return 0; // Conflict with adjacent vertex
        }
    }
    return 1; // No conflict, safe to color
}

// Function to solve the graph coloring problem
void graphColoring(Graph* g, int numColors) {
    int* colors = (int*)malloc(g->numVertices * sizeof(int));
    
    // Initialize all colors as NO_COLOR
    for (int i = 0; i < g->numVertices; i++) {
        colors[i] = NO_COLOR;
    }

    // Assign first color to the first vertex
    colors[0] = 0;

    // Color remaining vertices
    for (int i = 1; i < g->numVertices; i++) {
        // Check for color availability
        for (int color = 0; color < numColors; color++) {
            if (canColor(g, i, color, colors)) {
                colors[i] = color;
                break;
            }
        }
    }

    // Output the result
    printf("Vertex Color Assignment:\n");
    for (int i = 0; i < g->numVertices; i++) {
        printf("Vertex %d ---> Color %d\n", i, colors[i]);
    }

    free(colors);
}

int main() {
    Graph g;

    // Initialize graph with a predefined number of vertices
    int vertices = 7;
    initializeGraph(&g, vertices);

    // Manually adding edges
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 4);
    addEdge(&g, 3, 5);
    addEdge(&g, 4, 5);
    addEdge(&g, 5, 6);

    // Print the graph
    printGraph(&g);

    // Assuming we want to color with 3 colors
    int numColors = 3;
    graphColoring(&g, numColors);

    return 0;
}