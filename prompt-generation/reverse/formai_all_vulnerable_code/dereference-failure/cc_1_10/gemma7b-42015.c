//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Graph
{
    int numVertices;
    int **adjList;
} Graph;

Graph* createGraph(int numVertices)
{
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++)
    {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int srcVertex, int destVertex)
{
    if (graph->adjList[srcVertex] == NULL)
    {
        graph->adjList[srcVertex] = malloc(sizeof(int));
    }
    graph->adjList[srcVertex][0] = destVertex;
}

void traverseGraph(Graph* graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; graph->adjList[i] && j < graph->adjList[i][0]; j++)
        {
            printf("Edge from vertex %d to vertex %d\n", i, graph->adjList[i][j]);
        }
    }
}

int main()
{
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    traverseGraph(graph);

    return 0;
}