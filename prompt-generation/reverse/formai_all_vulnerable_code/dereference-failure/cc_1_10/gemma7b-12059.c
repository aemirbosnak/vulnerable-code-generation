//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NODES 10

int main()
{
    int i, j, k, l, m, n, total_nodes = 0, graph[MAX_NODES][MAX_NODES] = {{0}};
    char **topology_map = NULL;

    system("clear");
    topology_map = malloc(sizeof(char *) * MAX_NODES);
    for (i = 0; i < MAX_NODES; i++)
    {
        topology_map[i] = malloc(sizeof(char) * MAX_NODES);
    }

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    total_nodes = n;

    printf("Enter the connectivity matrix (0 for non-existent edges):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < total_nodes; i++)
    {
        topology_map[i] = "o";
    }

    for (i = 0; i < total_nodes; i++)
    {
        for (j = 0; j < total_nodes; j++)
        {
            if (graph[i][j] == 1)
            {
                topology_map[i][j] = "|";
            }
        }
    }

    printf("The topology map is:\n");
    for (i = 0; i < total_nodes; i++)
    {
        for (j = 0; j < total_nodes; j++)
        {
            printf("%c ", topology_map[i][j]);
        }
        printf("\n");
    }

    free(topology_map);

    return 0;
}