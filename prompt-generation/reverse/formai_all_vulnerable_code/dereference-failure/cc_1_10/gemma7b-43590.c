//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Vertices 10
#define MAX_Edges 20

typedef struct Graph
{
    int **adjList;
    int numVertices;
    int numEdges;
} Graph;

Graph *graph_create(int numVertices, int numEdges)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->adjList = (int **)malloc(numVertices * sizeof(int *));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;

    for (int i = 0; i < numVertices; i++)
    {
        graph->adjList[i] = (int *)malloc(numEdges * sizeof(int));
    }

    return graph;
}

void graph_add_edge(Graph *graph, int source, int destination)
{
    graph->adjList[source][destination] = 1;
}

void graph_print(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++)
        {
            if (graph->adjList[i][j] == 1)
            {
                printf("%d - %d\n", i, j);
            }
        }
    }
}

int main()
{
    Graph *graph = graph_create(5, 6);
    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 0, 2);
    graph_add_edge(graph, 1, 2);
    graph_add_edge(graph, 2, 3);
    graph_add_edge(graph, 3, 4);
    graph_add_edge(graph, 4, 0);

    graph_print(graph);

    free(graph);

    return 0;
}