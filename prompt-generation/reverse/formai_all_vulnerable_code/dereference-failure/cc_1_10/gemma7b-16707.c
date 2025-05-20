//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Graph
{
    int **adjList;
    int numVertices;
    char **vertices;
} Graph;

Graph *createGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (int **)malloc(numVertices * sizeof(int *));
    graph->vertices = (char **)malloc(numVertices * sizeof(char *));

    for (int i = 0; i < numVertices; i++)
    {
        graph->adjList[i] = (int *)malloc(MAX * sizeof(int));
        graph->vertices[i] = (char *)malloc(MAX * sizeof(char));
    }

    return graph;
}

void addEdge(Graph *graph, int u, int v)
{
    graph->adjList[u][v] = 1;
}

void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++)
        {
            if (graph->adjList[i][j] == 1)
            {
                printf("%c - %c\n", graph->vertices[i], graph->vertices[j]);
            }
        }
    }
}

int main()
{
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);

    printGraph(graph);

    return 0;
}