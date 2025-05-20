//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graphColoring(int **graph, int n, int **colors)
{
    int i, j, k, color, available, conflict;

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
                if (graph[i][k] != graph[i][j])
                {
                    if (colors[graph[i][k]] == colors[graph[i][j]])
                    {
                        conflict = 1;
                    }
                }
            }

            if (!conflict)
            {
                available = 0;
                for (k = 0; k < MAX; k++)
                {
                    if (colors[k] == -1)
                    {
                        available = 1;
                        colors[k] = graph[i][j];
                        break;
                    }
                }

                if (!available)
                {
                    printf("No solution found\n");
                    exit(1);
                }
            }
        }
    }

    printf("Solution found\n");
    for (i = 0; i < n; i++)
    {
        printf("Vertex %d has color %d\n", i + 1, colors[i]);
    }
}

int main()
{
    int n, m, i, j;
    int **graph;
    int **colors;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(m * sizeof(int));
    }

    colors = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    graphColoring(graph, n, colors);

    return 0;
}