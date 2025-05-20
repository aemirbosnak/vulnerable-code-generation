//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int k)
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
        int current = graph[i];
        if (visited[current] == 0)
        {
            visited[current] = 1;
            color[current] = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d colored with %d\n", i, color[i]);
    }
}

int main()
{
    int n = 5;
    int k = 3;

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;

    graph_coloring(graph, n, k);

    return 0;
}