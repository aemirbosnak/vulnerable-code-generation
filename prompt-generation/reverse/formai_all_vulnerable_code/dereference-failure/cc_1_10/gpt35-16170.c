//FormAI DATASET v1.0 Category: Graph representation ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

/* Structure to store an edge */
typedef struct
{
    int source, destination, weight;
} Edge;

/* Structure to store a graph */
typedef struct
{
    int num_vertices;
    int num_edges;
    Edge edge[MAX_VERTICES];
} Graph;

/* Function to create a graph with n vertices and m edges */
Graph* createGraph(int n, int m)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = n;
    graph->num_edges = m;
    return graph;
}

/* Function to add an edge to the graph */
void addEdge(Graph* graph, int source, int destination, int weight)
{
    graph->edge[graph->num_edges].source = source;
    graph->edge[graph->num_edges].destination = destination;
    graph->edge[graph->num_edges].weight = weight;
    graph->num_edges++;
}

/* Function to print the graph */
void printGraph(Graph* graph)
{
    int i;
    printf("Number of vertices: %d\n", graph->num_vertices);
    printf("Number of edges: %d\n", graph->num_edges);
    printf("Edges:\n");
    for(i = 0; i < graph->num_edges; i++)
    {
        printf("%d -- (%d) -- %d\n", graph->edge[i].source, graph->edge[i].weight, graph->edge[i].destination);
    }
}

/* Main Function */
int main()
{
    Graph* graph = createGraph(5, 7);
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 2, 4);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 2, 3, 6);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 8);
    printGraph(graph);
    return 0;
}