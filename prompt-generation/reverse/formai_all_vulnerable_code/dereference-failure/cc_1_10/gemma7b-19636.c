//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;
    int i, j, k, l;

    // Create a graph
    int **graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    // Connect nodes
    graph[0][1] = 1;
    graph[1][2] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;

    // Print the graph
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    // Mapper
    int **mapper = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        mapper[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
        {
            mapper[i][j] = -1;
        }
    }

    // Map nodes
    mapper[0][1] = 0;
    mapper[1][2] = 1;
    mapper[2][3] = 2;
    mapper[3][4] = 3;

    // Print the map
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", mapper[i][j]);
        }
        printf("\n");
    }

    return 0;
}