//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void display_topology(int **graph, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] != 0)
            {
                printf("%d ", graph[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int n, i, j;
    int **graph;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    graph = (int *)malloc(n * n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter the adjacency list: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d ", &graph[i][j]);
        }
    }

    display_topology(graph, n);

    free(graph);

    return 0;
}