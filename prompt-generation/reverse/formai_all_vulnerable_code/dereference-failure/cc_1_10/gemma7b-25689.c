//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graphColoring(int **graph, int n, int k)
{
    int i, j, color[n], used[k], maximumColor = 0;

    for (i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (i = 0; i < k; i++)
    {
        used[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            if (color[graph[i][j]] == -1)
            {
                int availableColor = -1;
                for (int c = 0; c < k; c++)
                {
                    if (!used[c])
                    {
                        availableColor = c;
                        used[c] = 1;
                        color[graph[i][j]] = availableColor;
                        break;
                    }
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Vertex %d has color %d\n", i, color[i]);
    }

    printf("The maximum number of colors used is %d\n", maximumColor);
}

int main()
{
    int n, k;
    scanf("Enter the number of vertices: ", &n);
    scanf("Enter the number of colors: ", &k);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(sizeof(int) * 2);
    }

    printf("Enter the adjacency list of the graph: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", graph[i][0]);
        for (int j = 0; j < graph[i][0]; j++)
        {
            scanf("%d ", graph[i][j + 1]);
        }
    }

    graphColoring(graph, n, k);

    return 0;
}