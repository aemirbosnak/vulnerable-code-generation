//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void map_topology(int **graph, int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] != 0)
            {
                printf("%d (%c) - ", graph[i][j], 'a' + i);
                for (k = 0; graph[i][j] > k; k++)
                {
                    printf("-> ");
                }
                printf("\n");
            }
        }
    }
}

int main()
{
    int n, i, j, **graph;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the adjacency matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    map_topology(graph, n);

    return 0;
}