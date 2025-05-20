//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **colors)
{
    for (int i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < graph[i][MAX]; j++)
        {
            if (colors[graph[i][j]] != -1)
            {
                colors[i] = -2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (colors[i] == -2)
        {
            printf("No solution\n");
            return;
        }
    }

    printf("Solution:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d colored %d\n", i, colors[i]);
    }
}

int main()
{
    int n, m;
    scanf("Enter the number of vertices: ", &n);
    scanf("Enter the number of edges: ", &m);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter the two vertices connected by the edge: ", &u, &v);
        graph[u][v] = 1;
    }

    int **colors = (int *)malloc(n * sizeof(int));

    graph_coloring(graph, n, colors);

    return 0;
}