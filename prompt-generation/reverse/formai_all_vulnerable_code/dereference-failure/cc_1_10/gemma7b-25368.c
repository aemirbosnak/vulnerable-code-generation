//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10

void graphColoringSynchronous(int **graph, int **colors, int nVertices)
{
    int i, j, k, color;

    for (i = 0; i < nVertices; i++)
    {
        colors[i] = -1;
    }

    for (i = 0; i < nVertices; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            k = graph[i][j];

            if (colors[k] != -1)
            {
                colors[i] = -1;
            }
            else
            {
                colors[i] = colors[k];
            }
        }
    }

    for (i = 0; i < nVertices; i++)
    {
        printf("Vertex %d has color %d\n", i, colors[i]);
    }
}

int main()
{
    int nVertices = 5;
    int **graph = malloc(nVertices * sizeof(int *));
    for (int i = 0; i < nVertices; i++)
    {
        graph[i] = malloc(2 * sizeof(int));
    }

    graph[0][0] = 1;
    graph[0][1] = 2;
    graph[1][0] = 3;
    graph[1][1] = 4;
    graph[2][0] = 4;
    graph[2][1] = 5;
    graph[3][0] = 5;
    graph[3][1] = 1;
    graph[4][0] = 1;
    graph[4][1] = 2;

    int **colors = malloc(nVertices * sizeof(int));
    for (int i = 0; i < nVertices; i++)
    {
        colors[i] = -1;
    }

    graphColoringSynchronous(graph, colors, nVertices);

    free(graph);
    free(colors);

    return 0;
}