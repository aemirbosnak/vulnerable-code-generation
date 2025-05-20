//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graph_coloring(int **graph, int n, int k)
{
    int *color = (int *)malloc(n * sizeof(int));
    int i, j, c, current_color = 0;

    for (i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (graph[i][j] && color[j] == -1)
            {
                c = current_color;
                current_color++;

                while (color[c] != -1)
                {
                    c++;
                }

                color[j] = c;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Vertex %d colored with %d\n", i, color[i]);
    }

    free(color);
}

int main()
{
    int n, k;
    int **graph;

    printf("Enter the number of vertices:");
    scanf("%d", &n);

    printf("Enter the number of colors:");
    scanf("%d", &k);

    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    printf("Enter the adjacency matrix:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    graph_coloring(graph, n, k);

    return 0;
}