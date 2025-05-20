//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 10

void graph_coloring(int **graph, int n)
{
    int *colors = malloc(n * sizeof(int));
    int i, j, k, color, conflict;

    for (i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            conflict = 0;
            for (k = 0; k < graph[i][0]; k++)
            {
                if (graph[i][k] == graph[j][0] && colors[k] == colors[i])
                {
                    conflict = 1;
                }
            }

            if (!conflict)
            {
                colors[i] = colors[j] ^ 1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Vertex %d has color %d\n", i, colors[i]);
    }

    free(colors);
}

int main()
{
    int **graph = malloc(MAX_V * sizeof(int *));
    for (int i = 0; i < MAX_V; i++)
    {
        graph[i] = malloc(sizeof(int) * 2);
    }

    graph[0][0] = 3;
    graph[0][1] = 2;
    graph[1][0] = 3;
    graph[1][1] = 2;
    graph[2][0] = 2;
    graph[2][1] = 1;
    graph[3][0] = 2;
    graph[3][1] = 1;

    graph_coloring(graph, MAX_V);

    free(graph);

    return 0;
}