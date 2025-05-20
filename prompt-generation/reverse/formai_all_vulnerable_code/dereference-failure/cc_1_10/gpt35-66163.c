//FormAI DATASET v1.0 Category: Graph representation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

// Structure to hold Graph
typedef struct Graph 
{
    int numVertices;
    int** adjMatrix;
} Graph;

// Function to add edges to the graph
void addEdge(Graph* graph, int src, int dest) 
{
    // Adding an edge from source to destination
    graph->adjMatrix[src][dest] = 1;

    // Adding an edge from destination to source since it is an undirected graph
    graph->adjMatrix[dest][src] = 1;
}

// Function to print the Graph in form of an adjacency matrix
void printGraph(Graph* graph) 
{
    for (int i = 0; i < graph->numVertices; i++) 
    {
        for (int j = 0; j < graph->numVertices; j++) 
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    printf("Enter the number of vertices: ");
    scanf("%d", &graph->numVertices);

    // Creating the adjacency matrix
    graph->adjMatrix = (int**) malloc(graph->numVertices * sizeof(int*));
    for (int i = 0; i < graph->numVertices; i++) 
    {
        graph->adjMatrix[i] = (int*) calloc(graph->numVertices, sizeof(int));
    }

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
   
    // Printing the Graph
    printf("Adjacency Matrix representation of Graph:\n");
    printGraph(graph);

    return 0;
}