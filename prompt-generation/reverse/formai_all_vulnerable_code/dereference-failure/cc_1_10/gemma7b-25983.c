//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **colors, int *visited, int current_color)
{
    int i, j, k, available = 0;

    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            for (j = 0; j < MAX; j++)
            {
                for (k = 0; k < MAX; k++)
                {
                    if (graph[i][j] && graph[i][k] && colors[j] != colors[k])
                    {
                        available = 1;
                    }
                }
            }

            if (available)
            {
                colors[i] = current_color;
                visited[i] = 1;
                graph_coloring(graph, n, colors, visited, current_color + 1);
            }
        }
    }
}

int main()
{
    int n, m, i, j, graph[MAX][MAX], colors[MAX], visited[MAX];

    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of edges: ", &m);

    graph_coloring(graph, n, colors, visited, 1);

    for (i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i + 1, colors[i]);
    }

    return 0;
}