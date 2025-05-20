//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int k)
{
    int **coloring = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        coloring[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (graph[i][j] && coloring[j] == -1)
            {
                coloring[i] = j;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d colored with color %d\n", i, coloring[i]);
    }
}

int main()
{
    int n, k;
    scanf("Enter the number of vertices: ", &n);
    scanf("Enter the number of colors: ", &k);

    int **graph = (int *)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    // Read the graph adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("Enter the adjacency value (1/0): ", &graph[i][j]);
        }
    }

    graph_coloring(graph, n, k);

    return 0;
}