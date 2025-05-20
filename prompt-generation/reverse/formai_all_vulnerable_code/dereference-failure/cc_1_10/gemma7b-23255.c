//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graphColoring(int **graph, int n, int k)
{
    int *color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] != 0)
            {
                color[j] = graph[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d colored with %d\n", i + 1, color[i] + 1);
    }
}

int main()
{
    int **graph = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        graph[i] = (int *)malloc(MAX * sizeof(int));
    }

    int n, k;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of colors: ");
    scanf("%d", &k);

    printf("Enter the adjacency matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    graphColoring(graph, n, k);

    return 0;
}