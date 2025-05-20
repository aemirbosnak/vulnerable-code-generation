//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int i, j, k, l, network_size, **topology_map, connections_num = 0;
    topology_map = (int**)malloc(MAX * sizeof(int*));
    for (i = 0; i < MAX; i++)
    {
        topology_map[i] = (int*)malloc(MAX * sizeof(int));
    }

    printf("Enter the number of nodes:");
    scanf("%d", &network_size);

    printf("Enter the number of connections:");
    scanf("%d", &connections_num);

    for (i = 0; i < network_size; i++)
    {
        for (j = 0; j < network_size; j++)
        {
            topology_map[i][j] = 0;
        }
    }

    for (i = 0; i < connections_num; i++)
    {
        printf("Enter the connection between node %d and node %d:", i + 1, connections_num + 1);
        scanf("%d %d", &k, &l);
        topology_map[k][l] = 1;
    }

    for (i = 0; i < network_size; i++)
    {
        for (j = 0; j < network_size; j++)
        {
            if (topology_map[i][j] == 1)
            {
                printf("Node %d is connected to Node %d\n", i + 1, j + 1);
            }
        }
    }

    free(topology_map);

    return 0;
}