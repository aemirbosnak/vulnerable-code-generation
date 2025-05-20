//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **colors)
{
    for (int i = 0; i < n; i++)
    {
        int color = -1;
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] && colors[j] != -1)
            {
                if (colors[j] == color)
                {
                    color = -1;
                    break;
                }
            }
        }
        if (color == -1)
        {
            printf("No solution found.\n");
            return;
        }
        colors[i] = color;
    }

    printf("Solution found:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d colored with %d\n", i, colors[i]);
    }
}

int main()
{
    int n, m;
    scanf("Enter the number of vertices: ", &n);
    scanf("Enter the number of edges: ", &m);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter the source vertex: ", &u);
        scanf("Enter the destination vertex: ", &v);
        graph[u][v] = 1;
    }

    int **colors = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    graph_coloring(graph, n, colors);

    return 0;
}