//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graphColoring(int **graph, int n, int **color, int currentColor)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && color[i] != color[j])
            {
                if (currentColor == 0)
                {
                    color[i] = color[j] = currentColor;
                    currentColor++;
                }
                else
                {
                    color[i] = color[j] = currentColor;
                    currentColor++;
                }
            }
        }
    }
}

int main()
{
    int n, m, i, j, currentColor = 1;
    int **graph, **color;

    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of edges: ", &m);

    graph = (int **)malloc(n * sizeof(int *));
    color = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
        color[i] = 0;
    }

    for (i = 0; i < m; i++)
    {
        scanf("Enter the source node: ", &i);
        scanf("Enter the destination node: ", &j);

        graph[i][j] = 1;
    }

    graphColoring(graph, n, color, currentColor);

    printf("The optimal coloring is:\n");

    for (i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i + 1, color[i]);
    }

    return 0;
}