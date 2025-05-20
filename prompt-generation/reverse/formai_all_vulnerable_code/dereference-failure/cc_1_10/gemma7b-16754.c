//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graph_coloring(int **graph, int n, int k)
{
    int **color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (int i = 0; i < k; i++)
    {
        int current_color = graph[i][0];
        for (int j = 1; j < n; j++)
        {
            if (graph[i][j] && color[j] == current_color)
            {
                color[j] = -1;
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
    int n, k;
    scanf("Enter the number of vertices:", &n);
    scanf("Enter the number of edges:", &k);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    for (int i = 0; i < k; i++)
    {
        int u, v;
        scanf("Enter the two vertices connected:", &u, &v);
        graph[u][v] = 1;
    }

    graph_coloring(graph, n, k);

    return 0;
}