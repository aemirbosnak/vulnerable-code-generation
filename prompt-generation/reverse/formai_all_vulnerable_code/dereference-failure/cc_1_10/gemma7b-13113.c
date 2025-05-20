//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void topo_map(int **graph, int n)
{
    int i, j, k;
    int **visited = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; graph[i][j] != -1; j++)
        {
            if (visited[graph[i][j]] == 0)
            {
                visited[graph[i][j]] = 1;
                printf("%d ", graph[i][j]);
            }
        }
    }

    free(visited);
}

int main()
{
    int n, m, i, j;
    int **graph = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        graph[i] = (int *)malloc(MAX * sizeof(int));
        for (j = 0; j < MAX; j++)
        {
            graph[i][j] = -1;
        }
    }

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
    {
        printf("Enter the source node: ");
        scanf("%d", &graph[i][0]);

        printf("Enter the destination node: ");
        scanf("%d", &graph[i][1]);
    }

    topo_map(graph, n);

    free(graph);

    return 0;
}