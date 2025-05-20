//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: medieval
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

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            conflict = 0;
            color = colors[graph[i][j]] == colors[i];

            if (!color)
            {
                colors[i] = graph[i][j];
            }
            else
            {
                conflict = 1;
            }
        }

        if (!conflict)
        {
            printf("Vertex %d colored with %d\n", i, colors[i]);
        }
        else
        {
            printf("No solution found\n");
            return;
        }
    }

    return;
}

int main()
{
    int n, k, i, j;
    int **graph;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of colors: ");
    scanf("%d", &k);

    graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    printf("Enter the adjacency list: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            scanf("%d ", &graph[i][j]);
        }
    }

    graph_coloring(graph, n, k);

    return 0;
}