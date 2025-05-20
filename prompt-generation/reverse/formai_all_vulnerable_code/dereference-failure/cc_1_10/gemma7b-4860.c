//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void graph_coloring(int **graph, int num_vertices, int *colors)
{
    for (int i = 0; i < num_vertices; i++)
    {
        colors[i] = -1;
    }

    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            if (graph[i][j] && colors[i] != colors[j])
            {
                colors[i] = colors[j] + 1;
            }
        }
    }
}

int main()
{
    int num_vertices = 5;
    int **graph = (int **)malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++)
    {
        graph[i] = (int *)malloc(num_vertices * sizeof(int));
    }

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][3] = 1;
    graph[2][4] = 1;
    graph[3][4] = 1;

    int *colors = (int *)malloc(num_vertices * sizeof(int));

    graph_coloring(graph, num_vertices, colors);

    for (int i = 0; i < num_vertices; i++)
    {
        printf("Vertex %d has color %d\n", i, colors[i]);
    }

    return 0;
}