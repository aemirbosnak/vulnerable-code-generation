//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int num_vertices, int *coloring)
{
    for (int i = 0; i < num_vertices; i++)
    {
        coloring[i] = -1;
    }

    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            if (graph[i][j] && coloring[i] != coloring[j])
            {
                coloring[i] = coloring[j];
            }
        }
    }

    return;
}

int main()
{
    int num_vertices = 5;
    int **graph = NULL;
    int *coloring = NULL;

    graph = (int **)malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++)
    {
        graph[i] = (int *)malloc(num_vertices * sizeof(int));
    }

    coloring = (int *)malloc(num_vertices * sizeof(int));

    graph[0][1] = graph[0][2] = graph[1][2] = graph[1][3] = 1;
    graph[2][3] = graph[3][4] = 1;

    graph_coloring(graph, num_vertices, coloring);

    for (int i = 0; i < num_vertices; i++)
    {
        printf("Vertex %d has color %d\n", i, coloring[i]);
    }

    return 0;
}