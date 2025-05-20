//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graphColoring(int **graph, int n, int k)
{
    int **color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[j][i] == 1)
            {
                int available = 0;
                for (int l = 0; l < n; l++)
                {
                    if (color[l] == graph[j][i] || color[l] == -1)
                    {
                        available = 1;
                    }
                }

                if (!available)
                {
                    return;
                }

                color[j] = graph[j][i];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d colored with color %d\n", i + 1, color[i]);
    }
}

int main()
{
    int n, k;
    scanf("Enter the number of vertices: ", &n);
    scanf("Enter the number of colors: ", &k);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    printf("Enter the adjacency matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d ", &graph[i][j]);
        }
    }

    graphColoring(graph, n, k);

    return 0;
}