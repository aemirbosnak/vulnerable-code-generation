//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void map_topology(int **graph, int n, int **visited, int current)
{
    int i, j, k;
    visited[current] = 1;

    printf("Node: %d ", current);

    for (i = 0; i < n; i++)
    {
        if (graph[current][i] && !visited[i])
        {
            map_topology(graph, n, visited, i);
        }
    }

    return;
}

int main()
{
    int n, i, j;
    int **graph;
    int **visited;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    graph = (int **)malloc(n * sizeof(int *));
    visited = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
        visited[i] = 0;
    }

    printf("Enter the adjacency matrix: ");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d ", &graph[i][j]);
        }
    }

    map_topology(graph, n, visited, 0);

    return 0;
}