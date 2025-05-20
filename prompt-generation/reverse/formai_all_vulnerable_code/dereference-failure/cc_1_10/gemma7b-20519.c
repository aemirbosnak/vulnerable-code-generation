//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void graphColoring(int **graph, int n, int k)
{
    int **colors = (int *)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        colors[i] = (int *)malloc(k * sizeof(int));
        for (int j = 0; j < k; j++)
            colors[i][j] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int color = graph[i][j];
            if (colors[i][color] == 0)
                colors[i][color] = 1;
            else
            {
                printf("No solution\n");
                return;
            }
        }
    }

    printf("Solution:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            printf("%d ", colors[i][j]);
        printf("\n");
    }
}

int main()
{
    int n, k;
    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of colors: ", &k);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        graph[i] = (int *)malloc(k * sizeof(int));

    // Read the graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            scanf("Enter the color of edge (%d, %d): ", &graph[i][j]);
    }

    graphColoring(graph, n, k);

    return 0;
}