//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Vertices 10

typedef struct Graph
{
    int **adjList;
    int numVertices;
    char **vertexNames;
} Graph;

Graph *createGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (int **)malloc(numVertices * sizeof(int *));
    graph->vertexNames = (char **)malloc(numVertices * sizeof(char *));

    for (int i = 0; i < numVertices; i++)
    {
        graph->adjList[i] = NULL;
        graph->vertexNames[i] = NULL;
    }

    return graph;
}

void addEdge(Graph *graph, int srcVertex, int destVertex)
{
    graph->adjList[srcVertex] = graph->adjList[srcVertex] ? graph->adjList[srcVertex] : (graph->adjList[srcVertex] = malloc(sizeof(int *)));
    graph->adjList[srcVertex][destVertex] = 1;
}

void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        printf("%s:", graph->vertexNames[i]);
        for (int j = 0; graph->adjList[i] && j < graph->adjList[i]  && graph->adjList[i][j]; j++)
        {
            printf(" --> %s", graph->vertexNames[graph->adjList[i][j]]);
        }
        printf("\n");
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
    addEdge(graph, 4, 2);

    printGraph(graph);

    free(graph);
    return 0;
}