//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void graph_coloring(int **graph, int n, int k)
{
    int **visited = (int *)malloc(n * sizeof(int));
    int *color = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        color[i] = -1;
    }

    for (int i = 0; i < k; i++)
    {
        int current_vertex = graph[i][0];
        int current_color = graph[i][1];

        if (visited[current_vertex] == 0)
        {
            visited[current_vertex] = 1;
            color[current_vertex] = current_color;
        }
        else if (color[current_vertex] != current_color)
        {
            return;
        }
    }

    printf("Graph coloring successful!\n");
    free(visited);
    free(color);
}

int main()
{
    int n = 5;
    int k = 3;

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(2 * sizeof(int));
    }

    graph[0][0] = 1;
    graph[0][1] = 2;
    graph[1][0] = 2;
    graph[1][1] = 3;
    graph[2][0] = 3;
    graph[2][1] = 1;
    graph[3][0] = 1;
    graph[3][1] = 2;
    graph[4][0] = 2;
    graph[4][1] = 3;

    graph_coloring(graph, n, k);

    free(graph);

    return 0;
}