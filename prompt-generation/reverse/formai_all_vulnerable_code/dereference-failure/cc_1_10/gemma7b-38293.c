//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void graph_coloring(int **graph, int num_vertices, int **colors)
{
    int i, j, k, color_available, current_color = 1;

    for (i = 0; i < num_vertices; i++)
    {
        color_available = 1;
        for (j = 0; j < num_vertices; j++)
        {
            if (graph[i][j] && colors[j] != current_color)
            {
                color_available = 0;
            }
        }

        if (color_available)
        {
            colors[i] = current_color;
        }
        else
        {
            current_color++;
            graph_coloring(graph, num_vertices, colors);
        }
    }
}

int main()
{
    int num_vertices = 5;
    int **graph = malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++)
    {
        graph[i] = malloc(num_vertices * sizeof(int));
    }

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][3] = 1;
    graph[2][4] = 1;
    graph[3][4] = 1;

    int **colors = malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++)
    {
        colors[i] = 0;
    }

    graph_coloring(graph, num_vertices, colors);

    for (int i = 0; i < num_vertices; i++)
    {
        printf("Vertex %d has color %d\n", i, colors[i]);
    }

    free(graph);
    free(colors);

    return 0;
}