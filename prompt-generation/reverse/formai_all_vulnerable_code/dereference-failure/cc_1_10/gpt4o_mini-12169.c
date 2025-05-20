//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure for Graph
typedef struct Graph {
    int numVertices;
    int **adjMatrix;
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
void printGraph(Graph *graph);
void greedyColoring(Graph *graph);
int isColorSafe(Graph *graph, int v, int color, int *colors);

int main() {
    int vertices = 5;
    Graph *graph = createGraph(vertices);

    // Creating a sample graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);
    greedyColoring(graph);

    // Free allocated memory for graph
    for(int i = 0; i < vertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
    return 0;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for(int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
        for(int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;  // Initialize adjacency matrix
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // Undirected graph
}

// Function to print the graph
void printGraph(Graph *graph) {
    printf("Adjacency Matrix of the Graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Greedy coloring algorithm
void greedyColoring(Graph *graph) {
    int *colors = (int *)malloc(graph->numVertices * sizeof(int));
    
    // Initialize all vertices as uncolored
    for (int i = 0; i < graph->numVertices; i++) {
        colors[i] = -1; // -1 means uncolored
    }

    // Assign the first color to first vertex
    colors[0] = 0;

    // Assign colors to remaining vertices
    for (int u = 1; u < graph->numVertices; u++) {
        // Check colors of adjacent vertices
        int *availableColors = (int *)calloc(graph->numVertices, sizeof(int));
        
        for (int v = 0; v < graph->numVertices; v++) {
            if (graph->adjMatrix[u][v] && colors[v] != -1) {
                availableColors[colors[v]] = 1; // Mark this color as unavailable
            }
        }

        // Find the first available color
        for (int color = 0; color < graph->numVertices; color++) {
            if (!availableColors[color]) {
                colors[u] = color;
                break;
            }
        }
        free(availableColors);
    }

    // Print the result
    printf("Vertex Coloring:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d ---> Color %d\n", i, colors[i]);
    }
    free(colors);
}