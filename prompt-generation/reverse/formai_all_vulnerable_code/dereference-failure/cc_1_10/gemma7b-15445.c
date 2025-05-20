//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

void graphColoring(int **graph, int n, int m)
{
    int *color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        int u = graph[i][0];
        int v = graph[i][1];

        if (color[u] == color[v])
        {
            printf("No solution found.\n");
            return;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("Node %d colored with %d\n", i, color[i]);
    }

    free(color);
}

int main()
{
    int n, m;
    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of edges: ", &m);

    int **graph = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        graph[i] = (int *)malloc(2 * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        scanf("Enter the two nodes connected by the edge: ", graph[i][0], graph[i][1]);
    }

    graphColoring(graph, n, m);

    return 0;
}