//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **color, int current_color)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < graph[i][0]; j++)
        {
            if (color[graph[i][j]] == current_color)
            {
                return;
            }
        }
    }

    color[current_color] = graph[current_color][0];
    current_color++;
    graph_coloring(graph, n, color, current_color);
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
        int u, v;
        scanf("Enter the two nodes connected by an edge: ", &u, &v);
        graph[u][v] = 1;
    }

    int **color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    int current_color = 0;
    graph_coloring(graph, n, color, current_color);

    for (int i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i + 1, color[i]);
    }

    return 0;
}