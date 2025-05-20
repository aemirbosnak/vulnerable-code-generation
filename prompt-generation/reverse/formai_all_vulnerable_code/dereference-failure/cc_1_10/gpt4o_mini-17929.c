//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20
#define COLORS 5

// Structure to represent a graph
typedef struct Graph {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Structure to represent a coloring configuration
typedef struct ColoringConfiguration {
    int colors[MAX_VERTICES];
    int numColorsUsed;
} ColoringConfiguration;

// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    // Initialize adjacency matrix with 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add edges to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1; // Undirected graph
}

// Function to check if the current color assignment is safe for vertex
bool isSafe(Graph* graph, int vertex, int color, int coloring[]) {
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] && coloring[i] == color) {
            return false;
        }
    }
    return true;
}

// Function to solve the graph coloring problem
bool graphColoringUtil(Graph* graph, ColoringConfiguration* config, int vertex) {
    if (vertex == graph->vertices) {
        return true; // All vertices are colored
    }

    for (int color = 1; color <= COLORS; color++) {
        if (isSafe(graph, vertex, color, config->colors)) {
            config->colors[vertex] = color;
            if (graphColoringUtil(graph, config, vertex + 1)) {
                return true; // Successfully colored the graph
            }
            config->colors[vertex] = 0; // Backtrack
        }
    }
    return false; // No valid coloring found
}

// Main function to color the graph
void graphColoring(Graph* graph) {
    ColoringConfiguration config;
    for (int i = 0; i < graph->vertices; i++) {
        config.colors[i] = 0; // Initialize color assignment
    }

    if (graphColoringUtil(graph, &config, 0)) {
        printf("Graph colored successfully with the following assignments:\n");
        for (int i = 0; i < graph->vertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, config.colors[i]);
        }
    } else {
        printf("Graph cannot be colored with %d colors.\n", COLORS);
    }
}

// Function to free the graph
void freeGraph(Graph* graph) {
    free(graph);
}

// Main program
int main() {
    int vertices, edges, src, dest;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (source dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            addEdge(graph, src, dest);
        } else {
            printf("Invalid edge! Vertex indices must be between 0 and %d.\n", vertices - 1);
            i--; // decrement to not count this edge
        }
    }

    graphColoring(graph);
    freeGraph(graph);
    return 0;
}