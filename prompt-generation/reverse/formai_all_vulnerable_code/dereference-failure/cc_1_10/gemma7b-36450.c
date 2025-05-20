//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graphColoring(int **graph, int n, int **color)
{
    for (int i = 0; i < n; i++)
    {
        int k = graph[i][0];
        for (int j = 1; j <= k; j++)
        {
            if (color[graph[i][j]] == color[graph[i][0]])
            {
                return;
            }
        }
        color[graph[i][0]] = color[graph[i][0]] + 1;
    }
    return;
}

int main()
{
    int n, m;
    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of edges: ", &m);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        scanf("Enter the source node: ", &graph[0][i]);
        scanf("Enter the destination node: ", &graph[1][i]);
    }

    int **color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    graphColoring(graph, n, color);

    for (int i = 0; i < n; i++)
    {
        printf("The color of node %d is %d\n", i + 1, color[i]);
    }

    return 0;
}