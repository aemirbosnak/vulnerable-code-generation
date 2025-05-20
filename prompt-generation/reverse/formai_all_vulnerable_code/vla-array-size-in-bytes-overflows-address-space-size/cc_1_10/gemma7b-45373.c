//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **colors)
{
    int i, j, k, color, used_colors[n];

    for (i = 0; i < n; i++)
    {
        used_colors[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            k = graph[i][j];
            color = used_colors[k];

            if (color == -1)
            {
                used_colors[k] = colors[i];
            }
            else if (color != colors[i])
            {
                printf("Error: Coloring conflict.\n");
                exit(1);
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Vertex %d colored with %d.\n", i, colors[i]);
    }
}

int main()
{
    int n, m, i, **graph, **colors;

    printf("Enter the number of vertices:");
    scanf("%d", &n);

    printf("Enter the number of edges:");
    scanf("%d", &m);

    graph = (int **)malloc(n * sizeof(int *));
    colors = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(m * sizeof(int));
    }

    graph_coloring(graph, n, colors);

    return 0;
}