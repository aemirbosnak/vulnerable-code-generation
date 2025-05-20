//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

void draw_network(int **graph, int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(graph[i][j] == 1)
            {
                printf("(%d, %d) --- ", i, j);
            }
        }
    }
    printf("\n");
}

int main()
{
    int **graph = NULL;
    int n = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    graph = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the adjacency matrix: ");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    draw_network(graph, n);

    free(graph);

    return 0;
}