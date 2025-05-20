//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int n, int current_color, int **visited, int **colors)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0 && graph[current_color][i] == 1)
        {
            visited[i] = 1;
            colors[i] = current_color;
            graph_coloring(graph, n, (current_color + 1) % n, visited, colors);
        }
    }
}

int main()
{
    int n, m;
    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of edges: ", &m);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    int **visited = (int *)malloc(n * sizeof(int));
    int **colors = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        colors[i] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter the two nodes: ", &u, &v);
        graph[u][v] = 1;
    }

    graph_coloring(graph, n, 0, visited, colors);

    printf("The coloring is complete.\n");
    for (int i = 0; i < n; i++)
    {
        printf("Node %d has color %d.\n", i, colors[i]);
    }

    return 0;
}