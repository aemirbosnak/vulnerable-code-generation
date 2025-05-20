//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Graph
{
    int V;  // number of vertices
    int E;  // number of edges
    int **adjMatrix;  // adjacency matrix
};

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int v, int w)
{
    graph->adjMatrix[v][w] = 1;
    graph->adjMatrix[w][v] = 1;
    graph->E++;
}

// Function to print the graph
void printGraph(struct Graph *graph)
{
    printf("Graph: \n");
    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    struct Graph graph;
    graph.V = 6;
    graph.E = 6;
    graph.adjMatrix = (int**)malloc(graph.V * sizeof(int*));
    for (int i = 0; i < graph.V; i++)
    {
        graph.adjMatrix[i] = (int*)malloc(graph.V * sizeof(int));
    }

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 4, 5);

    printGraph(&graph);

    return 0;
}