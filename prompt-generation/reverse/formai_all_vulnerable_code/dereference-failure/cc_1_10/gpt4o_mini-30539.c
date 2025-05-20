//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 99999

// Structure to represent the graph
typedef struct Graph {
    int vertices;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->vertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                graph->adjacency_matrix[i][j] = 0; // No self-loops
            } else {
                graph->adjacency_matrix[i][j] = INF; // Initial distance
            }
        }
    }

    return graph;
}

// Function to add edges to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjacency_matrix[src][dest] = 1; // Undirected graph
    graph->adjacency_matrix[dest][src] = 1;
}

// Function to print the adjacency matrix
void printGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            if (graph->adjacency_matrix[i][j] == INF) {
                printf("∞ ");
            } else {
                printf("%d ", graph->adjacency_matrix[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to check if a color assignment is safe for vertex v
int isSafe(int vertex, int color[], int c, Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjacency_matrix[vertex][i] == 1 && color[i] == c) {
            return 0; // Not safe
        }
    }
    return 1; // Safe
}

// Function to solve graph coloring problem
int graphColoringUtil(Graph* graph, int m, int color[], int vertex) {
    if (vertex == graph->vertices) {
        return 1; // All vertices colored successfully
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, color, c, graph)) {
            color[vertex] = c; // Assign color to vertex

            // Recur to color the next vertex
            if (graphColoringUtil(graph, m, color, vertex + 1)) {
                return 1; // Found a solution
            }

            // Backtrack
            color[vertex] = 0;
        }
    }
    return 0; // No solution found
}

// Function to solve the graph coloring problem and print the result
void graphColoring(Graph* graph, int m) {
    int* color = (int*) malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++) {
        color[i] = 0; // No color assigned
    }

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution found:\n");
        for (int i = 0; i < graph->vertices; i++) {
            printf("Vertex %d -> Color %d\n", i, color[i]);
        }
    } else {
        printf("No solution possible with given colors.\n");
    }

    free(color);
}

// Main function to demonstrate the graph coloring problem
int main() {
    int vertices, edges, m;

    printf("Welcome to the Graph Coloring Puzzle!\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Now, enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter the number of colors available (m): ");
    scanf("%d", &m);

    printGraph(graph);
    graphColoring(graph, m);

    free(graph);
    return 0;
}