//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10

typedef struct Graph
{
    int **adjList;
    int numVertices;
    int *visited;
} Graph;

Graph *createGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (int **)malloc(numVertices * sizeof(int *));
    graph->visited = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
    {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    graph->adjList[src] = (int *)realloc(graph->adjList[src], (graph->numVertices + 1) * sizeof(int));
    graph->adjList[src][graph->numVertices] = dest;
    graph->numVertices++;
}

void traverseGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        if (!graph->visited[i])
        {
            graph->visited[i] = 1;
            printf("Vertex %d: ", i);
            for (int j = 0; graph->adjList[i][j] != NULL; j++)
            {
                printf("-> Vertex %d ", graph->adjList[i][j]);
            }
            printf("\n");
        }
    }
}

int main()
{
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    traverseGraph(graph);
    free(graph);
    return 0;
}