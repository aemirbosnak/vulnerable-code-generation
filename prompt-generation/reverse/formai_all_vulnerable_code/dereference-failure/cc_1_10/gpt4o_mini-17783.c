//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function to check if the current color assignment is safe
int isSafe(int v, int graph[101][101], int color[], int c, int V) {
    for(int i = 0; i < V; i++) {
        if(graph[v][i] && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

// Function to solve the m coloring problem using backtracking
int graphColoringUtil(int graph[101][101], int m, int color[], int V, int v) {
    // Base case: if all vertices are assigned a color
    if(v == V) {
        return 1;
    }

    // Try different colors for vertex v
    for(int c = 1; c <= m; c++) {
        if(isSafe(v, graph, color, c, V)) {
            color[v] = c;  // Assign color c to vertex v

            // Recur to assign colors to the rest of the vertices
            if(graphColoringUtil(graph, m, color, V, v + 1)) {
                return 1;
            }

            // If color c doesn't lead to a solution, remove it
            color[v] = 0;
        }
    }
    return 0;  // If no color can be assigned, return 0
}

// The main function that solves the m coloring problem
int graphColoring(int graph[101][101], int m, int V) {
    int *color = (int *)malloc(V * sizeof(int));
    for(int i = 0; i < V; i++) {
        color[i] = 0;  // Initialize all vertices as uncolored
    }

    // Call the recursive utility function to solve the problem
    if(graphColoringUtil(graph, m, color, V, 0) == 0) {
        printf("Solution does not exist\n");
        free(color);
        return 0;
    }

    // Print the solution
    printf("Solution exists: Following are the assigned colors:\n");
    for(int i = 0; i < V; i++) {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }

    free(color);
    return 1;
}

// Function to read the graph input
void readGraph(int graph[101][101], int *V) {
    printf("Enter the number of vertices: ");
    scanf("%d", V);
    printf("Enter the adjacency matrix (%d x %d):\n", *V, *V);
    for(int i = 0; i < *V; i++) {
        for(int j = 0; j < *V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

int main() {
    int graph[101][101];
    int V, m;

    // Read the graph input
    readGraph(graph, &V);
    
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    // Solve the m coloring problem
    graphColoring(graph, m, V);

    return 0;
}