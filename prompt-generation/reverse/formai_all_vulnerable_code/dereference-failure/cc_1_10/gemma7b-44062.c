//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void graphColoring(int **graph, int n, int k)
{
    int **visited = (int *)malloc(n * sizeof(int));
    int **color = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        color[i] = -1;
    }

    for (int i = 0; i < k; i++)
    {
        int currentVertex = graph[i][0];
        int currentColor = graph[i][1];

        if (visited[currentVertex] == 0)
        {
            visited[currentVertex] = 1;
            color[currentVertex] = currentColor;
        }
        else
        {
            while (color[currentVertex] == currentColor)
            {
                currentColor++;
            }
            color[currentVertex] = currentColor;
        }
    }

    free(visited);
    free(color);
}

int main()
{
    int n = 5;
    int k = 5;
    int **graph = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(2 * sizeof(int));
    }

    graph[0][0] = 0;
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][1] = 2;
    graph[2][0] = 2;
    graph[2][1] = 3;
    graph[3][0] = 3;
    graph[3][1] = 4;
    graph[4][0] = 4;
    graph[4][1] = 5;

    graphColoring(graph, n, k);

    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d has color %d\n", graph[i][0], graph[i][1]);
    }

    free(graph);

    return 0;
}