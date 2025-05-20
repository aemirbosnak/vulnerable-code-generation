//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graphColoring(int **graph, int n, int currentColor, int **visited, int **colors)
{
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0 && graph[currentColor][i] == 1)
        {
            visited[i] = 1;
            colors[i] = currentColor;
            graphColoring(graph, n, currentColor + 1, visited, colors);
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

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter the u and v nodes: ", &u, &v);
        graph[u][v] = 1;
    }

    int **visited = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    int **colors = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        colors[i] = 0;
    }

    graphColoring(graph, n, 1, visited, colors);

    for (int i = 0; i < n; i++)
    {
        printf("The color of node %d is %d\n", i + 1, colors[i]);
    }

    return 0;
}