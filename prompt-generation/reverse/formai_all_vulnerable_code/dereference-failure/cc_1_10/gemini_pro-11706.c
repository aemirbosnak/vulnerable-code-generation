//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Graph data structure
typedef struct graph {
    int V;          // Number of vertices
    int E;          // Number of edges
    int **adj;      // Adjacency matrix
} Graph;

// Graph coloring state
typedef enum {
    UNCOLORED,  // Vertex is uncolored
    COLORED     // Vertex is colored
} ColoringState;

// Graph coloring
typedef struct coloring {
    ColoringState *state;  // Array of coloring states
    int *color;             // Array of colors
    int num_colors;         // Number of colors
} Coloring;

// Create a new graph
Graph *create_graph(int V, int E) {
    Graph *graph = malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;

    // Allocate memory for adjacency matrix
    graph->adj = malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = malloc(V * sizeof(int));
    }

    // Initialize adjacency matrix to 0
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }

    return graph;
}

// Add an edge to the graph
void add_edge(Graph *graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

// Create a new coloring
Coloring *create_coloring(int V) {
    Coloring *coloring = malloc(sizeof(Coloring));
    coloring->state = malloc(V * sizeof(ColoringState));
    coloring->color = malloc(V * sizeof(int));
    coloring->num_colors = 0;

    // Initialize coloring state to uncolored
    for (int i = 0; i < V; i++) {
        coloring->state[i] = UNCOLORED;
    }

    // Initialize color to -1
    for (int i = 0; i < V; i++) {
        coloring->color[i] = -1;
    }

    return coloring;
}

// Check if a coloring is valid
int is_valid_coloring(Graph *graph, Coloring *coloring) {
    // Check if any two adjacent vertices have the same color
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            if (graph->adj[i][j] == 1 && coloring->color[i] == coloring->color[j]) {
                return 0;
            }
        }
    }

    return 1;
}

// Color a graph
int color_graph(Graph *graph, Coloring *coloring) {
    // If all vertices are colored, return true
    if (coloring->num_colors == graph->V) {
        return 1;
    }

    // Try all possible colors for the next uncolored vertex
    for (int i = 0; i < graph->V; i++) {
        if (coloring->state[i] == UNCOLORED) {
            // Try each color and check if it is valid
            for (int color = 0; color < graph->V; color++) {
                coloring->color[i] = color;
                coloring->state[i] = COLORED;
                coloring->num_colors++;

                // If the coloring is valid, recurse
                if (is_valid_coloring(graph, coloring) && color_graph(graph, coloring)) {
                    return 1;
                }

                // If the coloring is not valid, reset the vertex to uncolored
                coloring->state[i] = UNCOLORED;
                coloring->num_colors--;
                coloring->color[i] = -1;
            }
        }
    }

    // If no valid coloring was found, return false
    return 0;
}

// Print a coloring
void print_coloring(Graph *graph, Coloring *coloring) {
    printf("Coloring:\n");
    for (int i = 0; i < graph->V; i++) {
        printf("Vertex %d: Color %d\n", i, coloring->color[i]);
    }
}

// Free a graph
void free_graph(Graph *graph) {
    // Free adjacency matrix
    for (int i = 0; i < graph->V; i++) {
        free(graph->adj[i]);
    }
    free(graph->adj);

    // Free graph
    free(graph);
}

// Free a coloring
void free_coloring(Coloring *coloring) {
    // Free coloring state
    free(coloring->state);

    // Free color
    free(coloring->color);

    // Free coloring
    free(coloring);
}

// Main function
int main() {
    // Create a graph
    Graph *graph = create_graph(4, 3);
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);

    // Create a coloring
    Coloring *coloring = create_coloring(graph->V);

    // Color the graph
    if (color_graph(graph, coloring)) {
        // Print the coloring
        print_coloring(graph, coloring);
    } else {
        printf("The graph cannot be colored.\n");
    }

    // Free the graph and coloring
    free_graph(graph);
    free_coloring(coloring);

    return 0;
}