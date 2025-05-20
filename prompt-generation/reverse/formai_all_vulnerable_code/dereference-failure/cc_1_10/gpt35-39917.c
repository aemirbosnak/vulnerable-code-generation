//FormAI DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

struct Graph *createGraph(int vertices)
{
    int i, j;
    struct Graph *graph = (struct Graph*) malloc(sizeof(struct Graph));
    if(graph == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    graph->numVertices = vertices;
    for(i = 0; i < vertices; i++)
    {
        for(j = 0; j < vertices; j++)
        {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void printGraph(struct Graph *graph)
{
    int i, j;
    for(i = 0; i < graph->numVertices; i++)
    {
        for(j = 0; j < graph->numVertices; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    struct Graph *graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    printGraph(graph);
    return 0;
}