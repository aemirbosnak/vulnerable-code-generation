//FormAI DATASET v1.0 Category: Graph representation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5

// Define a graph data structure
typedef struct Graph{
    int vertices[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix
    int numVertices; // number of vertices in the graph
} Graph;

// Function to add an edge to the graph
void addEdge(Graph* graph, int u, int v){
    graph->vertices[u][v] = 1;
    graph->vertices[v][u] = 1;
}

// Function to create a new graph
Graph* createGraph(int numVertices){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // Initialize all edges to 0
    for(int i=0; i<numVertices; i++){
        for(int j=0; j<numVertices; j++){
            graph->vertices[i][j] = 0;
        }
    }

    return graph;
}

// Function to print the graph
void printGraph(Graph* graph){
    printf("Adjacency Matrix:\n");
    for(int i=0; i<graph->numVertices; i++){
        for(int j=0; j<graph->numVertices; j++){
            printf("%d ", graph->vertices[i][j]);
        }
        printf("\n");
    }
}

int main(){
    // Create a new graph
    Graph* graph = createGraph(MAX_VERTICES);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);

    // Print the graph
    printGraph(graph);

    return 0;
}