//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void graph_coloring(int **graph, int n, int k)
{
    int **color = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        color[i] = (int *)malloc(k * sizeof(int));
        for (int j = 0; j < k; j++)
        {
            color[i][j] = 0;
        }
    }

    int **visited = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            int color_used = graph_coloring_recursive(graph, n, k, color, visited, i);
            if (color_used == -1)
            {
                printf("No solution found.\n");
                return;
            }
        }
    }

    printf("Solution found.\n");
    return;
}

int graph_coloring_recursive(int **graph, int n, int k, int **color, int **visited, int current_vertex)
{
    visited[current_vertex] = 1;

    for (int i = 0; i < k; i++)
    {
        if (color[current_vertex][i] == 0 && graph[current_vertex][i] == 1 && visited[graph[current_vertex][i]] == 0)
        {
            color[current_vertex][i] = 1;
            if (graph_coloring_recursive(graph, n, k, color, visited, graph[current_vertex][i]) == -1)
            {
                color[current_vertex][i] = 0;
                return -1;
            }
            else
            {
                return 0;
            }
        }
    }

    return -1;
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
        for (int j = 0; j < k; j++)
        {
            graph[i][j] = 0;
        }
    }

    scanf("Enter the adjacency list: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d ", &graph[i][j]);
        }
    }

    graph_coloring(graph, n, k);

    return 0;
}