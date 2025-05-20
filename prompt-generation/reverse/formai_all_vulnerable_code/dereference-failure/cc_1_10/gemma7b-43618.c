//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graphColoring(int **graph, int n, int **color, int *used)
{
    for (int i = 0; i < n; i++)
    {
        int currentVertex = graph[i];
        int currentColor = color[currentVertex];

        for (int j = 0; j < n; j++)
        {
            if (graph[j] == currentVertex && used[j] == currentColor)
            {
                used[currentVertex] = 0;
                color[currentVertex] = -1;
                graphColoring(graph, n, color, used);
            }
        }

        used[currentVertex] = currentColor;
    }
}

int main()
{
    int n = 5;
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][3] = 1;
    graph[2][4] = 1;
    graph[3][4] = 1;

    int **color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    int *used = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        used[i] = 0;
    }

    graphColoring(graph, n, color, used);

    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d has color %d\n", i, color[i]);
    }

    return 0;
}