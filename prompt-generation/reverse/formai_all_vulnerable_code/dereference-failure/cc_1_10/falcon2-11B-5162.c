//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

// Define a graph structure
typedef struct {
    int vertices;
    int edges;
    int* adjList;
} Graph;

// Define a function to initialize a graph
void initGraph(Graph* g, int vertices, int edges) {
    g->vertices = vertices;
    g->edges = edges;
    g->adjList = (int*)malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        g->adjList[i] = 0;
    }
}

// Define a function to add an edge to the graph
void addEdge(Graph* g, int v1, int v2) {
    g->adjList[v1]++;
    g->adjList[v2]++;
}

// Define a function to color a graph
void colorGraph(Graph* g, int color) {
    for (int i = 0; i < g->vertices; i++) {
        if (g->adjList[i] > 0) {
            for (int j = 0; j < g->vertices; j++) {
                if (g->adjList[i] == g->adjList[j]) {
                    printf("Error: Colored vertices are adjacent\n");
                    exit(1);
                }
            }
            printf("Colored vertex %d with color %d\n", i, color);
        }
    }
}

int main() {
    // Create a graph with 5 vertices and 3 edges
    Graph g = {5, 3, NULL};
    initGraph(&g, 5, 3);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 3, 4);
    
    // Color the graph with 2 colors
    colorGraph(&g, 1);
    colorGraph(&g, 2);
    
    return 0;
}