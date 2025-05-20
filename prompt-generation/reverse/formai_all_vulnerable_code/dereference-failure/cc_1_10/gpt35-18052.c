//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10 // maximum number of vertices in the graph

// structure to store a graph
struct Graph {
    int vertices; // number of vertices
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix
};

// creates a graph with n vertices
struct Graph* createGraph(int n) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// adds an edge between vertices x and y
void addEdge(struct Graph* graph, int x, int y) {
    graph->adjMatrix[x][y] = 1;
    graph->adjMatrix[y][x] = 1;
}

// function to check if the given color c is safe for vertex v
bool isSafe(struct Graph* graph, int vertex, int color, int colors[]) {
    for (int i = 0; i < graph->vertices; i++) { // loop through adjacent vertices
        if (graph->adjMatrix[vertex][i] == 1 && color == colors[i]) { // if adjacent vertex has same color
            return false;
        }
    }
    return true;
}

// recursive function to assign colors to all vertices
bool graphColoringUtil(struct Graph* graph, int colors[], int vertex) {
    if (vertex == graph->vertices) { // all vertices have been colored
        return true;
    }
    for (int i = 1; i <= 4; i++) { // loop through different colors
        if (isSafe(graph, vertex, i, colors)) { // check if color i is safe for vertex
            colors[vertex] = i;
            if (graphColoringUtil(graph, colors, vertex + 1)) { // recursive call to color next vertex
                return true;
            }
            colors[vertex] = 0; // backtrack if no solution found
        }
    }
    return false;
}

// function to color the graph
bool graphColoring(struct Graph* graph, int colors[]) {
    if (!graph) { // if graph is empty
        return false;
    }
    return graphColoringUtil(graph, colors, 0); // color vertices starting from first vertex
}

// driver function
int main() {
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    int colors[MAX_VERTICES] = {0}; // initialize all colors to 0
    if (graphColoring(graph, colors)) { // color the graph
        printf("The graph can be colored with 4 colors as follows:\n");
        for (int i = 0; i < graph->vertices; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("The graph cannot be colored with 4 colors.\n");
    }
    return 0;
}