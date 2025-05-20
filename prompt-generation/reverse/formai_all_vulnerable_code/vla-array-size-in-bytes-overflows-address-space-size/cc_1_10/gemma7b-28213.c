//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void topology_mapper(int **graph, int n)
{
    int i, j, k, count = 0, degree[n];
    for (i = 0; i < n; i++)
    {
        degree[i] = 0;
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] != 0)
            {
                degree[i]++;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Vertex %d has a degree of %d\n", i, degree[i]);
    }
}

int main()
{
    int n, i, j;
    int **graph;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the adjacency matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    topology_mapper(graph, n);

    return 0;
}