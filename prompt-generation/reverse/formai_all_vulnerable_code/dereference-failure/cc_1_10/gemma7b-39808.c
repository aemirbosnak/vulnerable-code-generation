//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int k)
{
    int *colors = (int *)malloc(n * sizeof(int));
    int i, j, color, conflict;

    for (i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < n; j++)
        {
            conflict = 0;
            for (color = 1; color <= MAX; color++)
            {
                if (graph[j][i] && colors[j] == color)
                {
                    conflict = 1;
                }
            }

            if (!conflict)
            {
                colors[j] = i + 1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Vertex %d colored with color %d\n", i + 1, colors[i]);
    }

    free(colors);
}

int main()
{
    int n, k;
    int **graph;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of colors: ");
    scanf("%d", &k);

    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    printf("Enter the adjacency matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    graph_coloring(graph, n, k);

    return 0;
}