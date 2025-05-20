//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int n, int k)
{
    int **color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < n; l++)
            {
                if (graph[j][l] && color[j] != color[l])
                {
                    color[l] = color[j] + 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d colored with %d\n", i, color[i]);
    }

    free(color);
}

int main()
{
    int n, k;
    scanf("Enter the number of vertices: ", &n);
    scanf("Enter the number of colors: ", &k);

    int **graph = (int *)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("Enter the adjacency matrix element (graph[%d][%d]) : ", &graph[i][j]);
        }
    }

    graph_coloring(graph, n, k);

    free(graph);

    return 0;
}