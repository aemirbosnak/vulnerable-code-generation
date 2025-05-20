//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the graph structure
typedef struct Graph {
    int numVertices;
    int **adjacentVertices;
} Graph;

// Define the vertex structure
typedef struct Vertex {
    int id;
    int color;
} Vertex;

// Function to create a graph
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjacentVertices = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjacentVertices[i] = (int*)malloc(numVertices * sizeof(int));
    }
    return graph;
}

// Function to color the graph
void colorGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        graph->adjacentVertices[i][i] = 0; // Set the diagonal element to 0
    }
    for (int i = 0; i < graph->numVertices; i++) {
        graph->adjacentVertices[i][i] = 1; // Set the diagonal element to 1
    }
    int color = 1;
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacentVertices[i][i] == 0) {
            for (int j = 0; j < graph->numVertices; j++) {
                if (graph->adjacentVertices[i][j] == 1) {
                    graph->adjacentVertices[i][j] = 0; // Assign color to vertex i
                }
            }
            graph->adjacentVertices[i][i] = 1; // Assign color to vertex i
            color++;
        }
    }
}

// Function to check if any two adjacent vertices have the same color
bool checkAdjacentVertices(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjacentVertices[i][j] == graph->adjacentVertices[j][i]) {
                printf("Error: Adjacent vertices have the same color\n");
                return false;
            }
        }
    }
    printf("Success: All vertices have unique colors\n");
    return true;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacentVertices[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int numVertices = 5;
    Graph* graph = createGraph(numVertices);
    colorGraph(graph);
    checkAdjacentVertices(graph);
    printGraph(graph);
    free(graph->adjacentVertices);
    free(graph);
    return 0;
}