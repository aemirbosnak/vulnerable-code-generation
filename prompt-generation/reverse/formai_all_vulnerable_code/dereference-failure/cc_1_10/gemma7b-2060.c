//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: beginner-friendly
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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (graph[i][j] && color[j] == -1)
            {
                color[j] = i + 1;
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
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of colors: ");
    scanf("%d", &k);

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
            scanf("%d", &graph[i][j]);
        }
    }

    graphColoring(graph, n, k);

    return 0;
}