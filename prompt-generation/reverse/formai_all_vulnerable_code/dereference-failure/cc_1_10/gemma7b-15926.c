//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Graph
{
    int **adj;
    int *visited;
    int numVertices;
} Graph;

Graph *createGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->adj = (int **)malloc(sizeof(int *) * numVertices);
    graph->visited = (int *)malloc(sizeof(int) * numVertices);
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++)
    {
        graph->adj[i] = (int *)malloc(sizeof(int) * numVertices);
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph *graph, int u, int v)
{
    graph->adj[u][v] = 1;
}

void traverseGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        if (!graph->visited[i])
        {
            graph->visited[i] = 1;
            printf("Vertex %d: ", i);
            for (int j = 0; j < graph->numVertices; j++)
            {
                if (graph->adj[i][j] && graph->visited[j] == 0)
                {
                    printf("-> Vertex %d ", j);
                }
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
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 1);

    traverseGraph(graph);

    return 0;
}