//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graph_coloring(int **graph, int n, int k)
{
    int *colors = (int *)malloc(n * sizeof(int));
    int i, j, color = 0, conflict = 0;

    for (i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            if (colors[graph[i][j]] == colors[i])
            {
                conflict = 1;
            }
        }
    }

    if (conflict)
    {
        printf("No solution found.\n");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            printf("Vertex %d colored with %d.\n", i + 1, colors[i] + 1);
        }
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

    printf("Enter the adjacency list: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d ", &graph[i][j]);
        }
    }

    graph_coloring(graph, n, k);

    return 0;
}