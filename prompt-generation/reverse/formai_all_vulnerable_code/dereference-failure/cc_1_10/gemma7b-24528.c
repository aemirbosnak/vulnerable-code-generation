//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Graph
{
    int **adjList;
    int numVertices;
    int numEdges;
} Graph;

Graph* createGraph(int numVertices)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjList = (int**)malloc(numVertices * sizeof(int*));
    graph->numVertices = numVertices;
    graph->numEdges = 0;

    for(int i = 0; i < numVertices; i++)
    {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest)
{
    graph->adjList[src] = (int*)realloc(graph->adjList[src], (graph->numEdges + 1) * sizeof(int));
    graph->adjList[src][graph->numEdges] = dest;
    graph->numEdges++;
}

void traverseGraph(Graph* graph)
{
    for(int i = 0; i < graph->numVertices; i++)
    {
        for(int j = 0; graph->adjList[i] && j < graph->numEdges; j++)
        {
            printf("%d ", graph->adjList[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    traverseGraph(graph);

    free(graph);

    return 0;
}