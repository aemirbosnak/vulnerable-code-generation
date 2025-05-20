//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, i, j, k;
    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of edges: ", &m);

    // Create a graph
    int **graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(m * sizeof(int));
    }

    // Read the edges
    for (i = 0; i < m; i++)
    {
        scanf("Enter the source node: ", &k);
        scanf("Enter the destination node: ", &j);
        graph[k][j] = 1;
    }

    // Color the graph
    int **colors = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && colors[i] != colors[j])
            {
                colors[j] = k++;
            }
        }
    }

    // Print the colors
    for (i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i, colors[i]);
    }

    return 0;
}