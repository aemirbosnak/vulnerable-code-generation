//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void create_topology(int **graph, int n)
{
    graph = (int *)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int **graph, int n, int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void traverse(int **graph, int n, int current)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[current][i] && i != current)
        {
            printf("%d ", i);
            traverse(graph, n, i);
        }
    }
}

int main()
{
    int n = 5;
    int **graph;
    create_topology(&graph, n);
    add_edge(graph, n, 0, 1);
    add_edge(graph, n, 1, 2);
    add_edge(graph, n, 2, 3);
    add_edge(graph, n, 3, 4);
    add_edge(graph, n, 4, 0);

    traverse(graph, n, 0);

    return 0;
}