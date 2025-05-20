//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Structure to represent a graph
typedef struct Graph {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function declarations
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int from, int to);
bool isSafe(int vertex, Graph* graph, int* color, int c);
bool graphColoringUtil(Graph* graph, int m, int* color, int v);
void graphColoring(Graph* graph, int m);
void freeGraph(Graph* graph);

// Main function
int main() {
    int vertices, edges, from, to, colors;

    printf("Welcome to the Graph Coloring Problem Solver!\n");
    printf("Please enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    // Check for valid input
    if (vertices < 1 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices. Please enter between 1 and %d.\n", MAX_VERTICES);
        return 1;
    }

    Graph* graph = createGraph(vertices);

    printf("How many edges do you want to add?: ");
    scanf("%d", &edges);

    printf("Let's add the edges!\n");
    for (int i = 0; i < edges; ++i) {
        printf("Enter edge %d (format: from to): ", i + 1);
        scanf("%d %d", &from, &to);
        // Adding edge only if vertices are valid
        if (from >= 0 && from < vertices && to >= 0 && to < vertices) {
            addEdge(graph, from, to);
        } else {
            printf("Invalid vertices! Please provide values between 0 and %d.\n", vertices - 1);
            i--; // Decrement to retry the addition of an edge
        }
    }

    printf("Now, how many colors do you want to use?: ");
    scanf("%d", &colors);

    graphColoring(graph, colors);

    freeGraph(graph);
    return 0;
}

// Function to create the graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            graph->adjMatrix[i][j] = 0; // initialize adjacency matrix
        }
    }
    return graph;
}

// Function to add an edge
void addEdge(Graph* graph, int from, int to) {
    graph->adjMatrix[from][to] = 1;
    graph->adjMatrix[to][from] = 1; // as the graph is undirected
}

// Function to check if it's safe to color a vertex
bool isSafe(int vertex, Graph* graph, int* color, int c) {
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[vertex][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Utility function for graph coloring
bool graphColoringUtil(Graph* graph, int m, int* color, int v) {
    if (v == graph->vertices) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1)) return true;
            color[v] = 0; // Backtrack
        }
    }
    return false;
}

// Main function to solve the graph coloring problem
void graphColoring(Graph* graph, int m) {
    int* color = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++) {
        color[i] = 0; // Initialize color array
    }

    printf("Attempting to color the graph with %d colors...\n", m);
    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist with the given number of colors.\n");
    } else {
        printf("Coloring Solution:\n");
        for (int i = 0; i < graph->vertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, color[i]);
        }
    }

    free(color);
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    free(graph);
}