//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// A data structure to represent a graph
struct Graph {
    int V;          // Number of vertices
    int E;          // Number of edges
    int **adj;      // Adjacency matrix
};

// A data structure to represent a color
struct Color {
    int r;          // Red component
    int g;          // Green component
    int b;          // Blue component
};

// A function to create a new graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    // Create the adjacency matrix
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
void addEdge(struct Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

// A function to print a graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// A function to create a new color
struct Color* createColor(int r, int g, int b) {
    struct Color* color = (struct Color*)malloc(sizeof(struct Color));
    color->r = r;
    color->g = g;
    color->b = b;

    return color;
}

// A function to print a color
void printColor(struct Color* color) {
    printf("(%d, %d, %d)\n", color->r, color->g, color->b);
}

// A function to color a graph using the greedy algorithm
void colorGraph(struct Graph* graph, struct Color** colors) {
    // Initialize the colors of all vertices to white
    for (int i = 0; i < graph->V; i++) {
        colors[i] = createColor(255, 255, 255);
    }

    // Iterate over the vertices in order of decreasing degree
    int degrees[graph->V];
    for (int i = 0; i < graph->V; i++) {
        degrees[i] = 0;
        for (int j = 0; j < graph->V; j++) {
            degrees[i] += graph->adj[i][j];
        }
    }

    int sortedVertices[graph->V];
    for (int i = 0; i < graph->V; i++) {
        sortedVertices[i] = i;
    }

    for (int i = 0; i < graph->V - 1; i++) {
        for (int j = i + 1; j < graph->V; j++) {
            if (degrees[sortedVertices[i]] < degrees[sortedVertices[j]]) {
                int temp = sortedVertices[i];
                sortedVertices[i] = sortedVertices[j];
                sortedVertices[j] = temp;
            }
        }
    }

    // Iterate over the vertices
    for (int i = 0; i < graph->V; i++) {
        int u = sortedVertices[i];

        // Iterate over the neighbors of the current vertex
        for (int j = 0; j < graph->V; j++) {
            if (graph->adj[u][j] == 1) {
                // If the neighbor is already colored, check if the color is different
                if (colors[j] != NULL) {
                    // If the color is different, continue to the next neighbor
                    continue;
                }
            }

            // If the neighbor is not colored, assign it the first available color
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;
            colors[j] = createColor(r, g, b);
        }
    }
}

// A function to print the colors of a graph
void printColors(struct Graph* graph, struct Color** colors) {
    for (int i = 0; i < graph->V; i++) {
        printf("Vertex %d: ", i);
        printColor(colors[i]);
    }
}

// A function to test the graph coloring algorithm
int main() {
    // Create a graph
    struct Graph* graph = createGraph(5, 6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    // Color the graph
    struct Color** colors = (struct Color**)malloc(graph->V * sizeof(struct Color*));
    colorGraph(graph, colors);

    // Print the colors
    printColors(graph, colors);

    return 0;
}