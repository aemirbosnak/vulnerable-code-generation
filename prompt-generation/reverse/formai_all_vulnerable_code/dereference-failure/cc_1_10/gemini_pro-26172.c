//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
// A cheerful C program to solve the Graph Coloring Problem

#include <stdio.h>
#include <stdlib.h>

// A structure to represent a graph
typedef struct Graph {
    int V;          // Number of vertices
    int E;          // Number of edges
    int **adj;      // Adjacency matrix
} Graph;

// A structure to represent a solution
typedef struct Solution {
    int *color;     // Color of each vertex
} Solution;

// A function to create a new graph
Graph *createGraph(int V, int E) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;

    // Allocate memory for the adjacency matrix
    graph->adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int *)malloc(V * sizeof(int));
    }

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }

    return graph;
}

// A function to add an edge to a graph
void addEdge(Graph *graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

// A function to create a new solution
Solution *createSolution(int V) {
    Solution *solution = (Solution *)malloc(sizeof(Solution));
    solution->color = (int *)malloc(V * sizeof(int));

    // Initialize the color of each vertex to 0
    for (int i = 0; i < V; i++) {
        solution->color[i] = 0;
    }

    return solution;
}

// A function to check if a solution is valid
int isValidSolution(Graph *graph, Solution *solution) {
    // Check if any two adjacent vertices have the same color
    for (int i = 0; i < graph->V; i++) {
        for (int j = i + 1; j < graph->V; j++) {
            if (graph->adj[i][j] == 1 && solution->color[i] == solution->color[j]) {
                return 0;
            }
        }
    }

    return 1;
}

// A function to print a solution
void printSolution(Solution *solution) {
    printf("Colors of vertices:\n");
    for (int i = 0; i < solution->color; i++) {
        printf("%d ", solution->color[i]);
    }
    printf("\n");
}

// A function to find all solutions to the Graph Coloring Problem
void graphColoring(Graph *graph, Solution *solution, int vertex) {
    // If all vertices have been colored, check if the solution is valid and print it
    if (vertex == graph->V) {
        if (isValidSolution(graph, solution)) {
            printSolution(solution);
        }
        return;
    }

    // Try all possible colors for the current vertex
    for (int color = 1; color <= graph->V; color++) {
        // Check if the current color is valid for the current vertex
        int valid = 1;
        for (int i = 0; i < graph->V; i++) {
            if (graph->adj[vertex][i] == 1 && solution->color[i] == color) {
                valid = 0;
                break;
            }
        }

        // If the current color is valid, set the color of the current vertex
        // and continue to color the remaining vertices
        if (valid) {
            solution->color[vertex] = color;
            graphColoring(graph, solution, vertex + 1);
        }
    }
}

// A main function to test the graph coloring program
int main() {
    // Create a graph
    Graph *graph = createGraph(4, 5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    // Create a solution
    Solution *solution = createSolution(graph->V);

    // Find all solutions to the Graph Coloring Problem
    graphColoring(graph, solution, 0);

    return 0;
}