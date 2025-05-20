//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

void draw_network(int **graph, int num_nodes)
{
    int i, j, k;
    for (i = 0; i < num_nodes; i++)
    {
        for (j = 0; j < num_nodes; j++)
        {
            if (graph[i][j] > 0)
            {
                printf("%d ", graph[i][j]);
            }
        }
        printf("\n");
    }

    printf("--------------------------------------------------------\n");
}

int main()
{
    int **graph;
    int num_nodes;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    graph = (int **)malloc(num_nodes * sizeof(int *));
    for (int i = 0; i < num_nodes; i++)
    {
        graph[i] = (int *)malloc(num_nodes * sizeof(int));
    }

    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < num_nodes; i++)
    {
        for (int j = 0; j < num_nodes; j++)
        {
            scanf("%d ", &graph[i][j]);
        }
    }

    draw_network(graph, num_nodes);

    return 0;
}