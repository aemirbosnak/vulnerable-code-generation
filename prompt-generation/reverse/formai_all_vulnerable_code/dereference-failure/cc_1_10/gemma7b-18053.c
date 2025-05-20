//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **colors)
{
    int i, j, k, available, color;

    for (i = 0; i < n; i++)
    {
        available = 1;
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && colors[j] == colors[i])
            {
                available = 0;
            }
        }

        if (available)
        {
            for (k = 1; k <= MAX; k++)
            {
                if (!colors[k] && available)
                {
                    colors[i] = k;
                    break;
                }
            }
        }
    }
}

int main()
{
    int n, m, i, j, graph[MAX][MAX], colors[MAX];

    scanf("Enter the number of nodes:", &n);
    scanf("Enter the number of edges:", &m);

    graph_coloring(graph, n, colors);

    for (i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i + 1, colors[i]);
    }

    return 0;
}