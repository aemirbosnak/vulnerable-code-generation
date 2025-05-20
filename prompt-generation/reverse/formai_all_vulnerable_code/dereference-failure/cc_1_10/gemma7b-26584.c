//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int num_vertices)
{
    int *colors = (int *)malloc(num_vertices * sizeof(int));
    int i, j, k, color = 1, conflict = 0;

    for (i = 0; i < num_vertices; i++)
    {
        colors[i] = -1;
    }

    for (i = 0; i < num_vertices; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            k = graph[i][j];
            if (colors[i] == colors[k])
            {
                conflict = 1;
            }
        }
    }

    if (conflict)
    {
        printf("No coloring possible.\n");
    }
    else
    {
        for (i = 0; i < num_vertices; i++)
        {
            printf("Vertex %d colored with %d.\n", i, colors[i]);
        }
    }

    free(colors);
}

int main()
{
    int num_vertices = 5;
    int **graph = (int **)malloc(num_vertices * sizeof(int *));
    graph[0] = (int *)malloc(num_vertices * sizeof(int));
    graph[1] = (int *)malloc(num_vertices * sizeof(int));
    graph[2] = (int *)malloc(num_vertices * sizeof(int));
    graph[3] = (int *)malloc(num_vertices * sizeof(int));
    graph[4] = (int *)malloc(num_vertices * sizeof(int));

    graph[0][0] = 1;
    graph[0][1] = 2;
    graph[1][0] = 2;
    graph[1][1] = 3;
    graph[2][0] = 3;
    graph[2][1] = 4;
    graph[3][0] = 4;
    graph[3][1] = 5;
    graph[4][0] = 5;

    graph_coloring(graph, num_vertices);

    return 0;
}