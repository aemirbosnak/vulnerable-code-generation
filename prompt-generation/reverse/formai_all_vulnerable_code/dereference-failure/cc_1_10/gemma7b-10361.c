//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10

void graph_coloring(int **graph, int nVertices, int **colors)
{
    int i, j, k, color, available;

    for (i = 0; i < nVertices; i++)
    {
        available = 1;
        for (j = 0; j < nVertices; j++)
        {
            if (graph[i][j] && colors[j] == colors[i])
            {
                available = 0;
            }
        }

        if (available)
        {
            colors[i] = 1;
        }
        else
        {
            colors[i] = -1;
        }
    }
}

int main()
{
    int **graph = NULL;
    int nVertices, i, colors[MAX_Vertices];

    nVertices = 5;
    graph = (int **)malloc(nVertices * sizeof(int *));
    for (i = 0; i < nVertices; i++)
    {
        graph[i] = (int *)malloc(nVertices * sizeof(int));
    }

    graph[0][1] = graph[0][2] = 1;
    graph[1][2] = graph[2][3] = 1;
    graph[3][4] = 1;

    graph_coloring(graph, nVertices, colors);

    for (i = 0; i < nVertices; i++)
    {
        printf("Vertex %d has color %d\n", i, colors[i]);
    }

    free(graph);

    return 0;
}