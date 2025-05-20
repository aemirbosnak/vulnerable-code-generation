//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Structure to represent a Graph
typedef struct {
    int vertices;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a Graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph->adj[i][j] = 0;
    return graph;
}

// Function to add an edge to the Graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1; // Undirected graph
}

// Function to display the Graph
void displayGraph(Graph* graph) {
    printf("Graph Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the current color assignment is safe for vertex v
bool isSafe(Graph* graph, int v, int color[], int c) {
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adj[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Function to solve the Graph Coloring Problem using Backtracking
bool graphColoringUtil(Graph* graph, int m, int color[], int v) {
    if (v == graph->vertices) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, v, color, c)) {
            color[v] = c; // Assign color c to vertex v

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            color[v] = 0; // Backtrack
        }
    }
    return false;
}

// Function to initiate graph coloring
void graphColoring(Graph* graph, int m) {
    int* color = malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++)
        color[i] = 0; // Initialize colors as 0

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution exists: Assigned colors are:\n");
        for (int i = 0; i < graph->vertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, color[i]);
        }
    } else {
        printf("Solution does not exist for %d colors\n", m);
    }

    free(color);
}

// Main function with a puzzling setup
int main() {
    printf("Welcome to the Puzzle of Colorful Graphs!\n");
    int vertices, edges, m;

    printf("Enter the number of vertices (1 to %d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    if (vertices < 1 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices! Please enter a number between 1 and %d.\n", MAX_VERTICES);
        return 1;
    }

    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    printf("Input the edges (format: src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        if (src < vertices && dest < vertices) {
            addEdge(graph, src, dest);
        } else {
            printf("Invalid edge (%d, %d)! Vertices must be between 0 and %d.\n", src, dest, vertices - 1);
            i--; // Ask for the edge again
        }
    }

    displayGraph(graph);

    printf("Enter the number of colors to use (m): ");
    scanf("%d", &m);

    // Start the graph coloring puzzle
    graphColoring(graph, m);
    
    // Cleanup
    free(graph);
    return 0;
}