//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main()
{
    int i, j, k, l, n, m;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of connections: ");
    scanf("%d", &m);

    // Create a graph
    int **graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(m * sizeof(int));
    }

    // Enter the connections
    for (i = 0; i < m; i++)
    {
        printf("Enter the source node: ");
        scanf("%d", &k);

        printf("Enter the destination node: ");
        scanf("%d", &l);

        graph[k][l] = 1;
    }

    // Print the topology
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                printf("%d - ", j);
            }
        }

        printf("\n");
    }

    return 0;
}