//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10
#define MAX_Edges 20

typedef struct Graph
{
    int **adjList;
    int numVertices;
    int numEdges;
} Graph;

Graph* createGraph()
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjList = (int**)malloc(MAX_Vertices * sizeof(int*));
    graph->numVertices = 0;
    graph->numEdges = 0;

    for (int i = 0; i < MAX_Vertices; i++)
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

void printGraph(Graph* graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->numEdges; j++)
        {
            if (graph->adjList[i][j] != NULL)
            {
                printf("%d ", graph->adjList[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    Graph* graph = createGraph();

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);

    printGraph(graph);

    return 0;
}