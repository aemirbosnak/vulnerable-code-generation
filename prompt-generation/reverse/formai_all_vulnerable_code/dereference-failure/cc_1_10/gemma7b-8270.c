//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Graph
{
    int **adjList;
    int numVertices;
} Graph;

void graphColor(Graph *graph)
{
    int i, j, k, color = 0, conflict = 0;
    int *colorArr = (int *)malloc(graph->numVertices * sizeof(int));

    for (i = 0; i < graph->numVertices; i++)
    {
        colorArr[i] = -1;
    }

    for (i = 0; i < graph->numVertices; i++)
    {
        for (j = 0; j < graph->adjList[i][0]; j++)
        {
            k = graph->adjList[i][j];
            if (colorArr[k] == colorArr[i])
            {
                conflict = 1;
            }
        }
    }

    if (!conflict)
    {
        for (i = 0; i < graph->numVertices; i++)
        {
            colorArr[i] = color++;
        }
    }

    free(colorArr);
}

int main()
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = 5;
    graph->adjList = (int **)malloc(graph->numVertices * sizeof(int *));

    graph->adjList[0] = (int *)malloc(2 * sizeof(int));
    graph->adjList[0][0] = 1;
    graph->adjList[0][1] = 2;

    graph->adjList[1] = (int *)malloc(2 * sizeof(int));
    graph->adjList[1][0] = 0;
    graph->adjList[1][1] = 3;

    graph->adjList[2] = (int *)malloc(2 * sizeof(int));
    graph->adjList[2][0] = 1;
    graph->adjList[2][1] = 4;

    graph->adjList[3] = (int *)malloc(2 * sizeof(int));
    graph->adjList[3][0] = 2;
    graph->adjList[3][1] = 4;

    graph->adjList[4] = (int *)malloc(2 * sizeof(int));
    graph->adjList[4][0] = 3;
    graph->adjList[4][1] = 5;

    graphColor(graph);

    for (int i = 0; i < graph->numVertices; i++)
    {
        printf("Vertex %d has color %d\n", i, graph->adjList[i][1]);
    }

    free(graph);

    return 0;
}