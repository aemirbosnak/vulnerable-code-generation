//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 10

void graph_coloring(int **graph, int n, int k)
{
    int *color = (int *)malloc(n * sizeof(int));
    int i, j, v, c, conflict = 0;

    for (i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (v = 0; v < n; v++)
    {
        for (i = 0; i < graph[v][0]; i++)
        {
            c = graph[v][i + 1];

            if (color[c] == color[v] || color[c] == -1)
            {
                conflict = 1;
            }
        }
    }

    if (conflict)
    {
        printf("No coloring solution found.\n");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            printf("Vertex %d colored with %d.\n", i, color[i]);
        }
    }

    free(color);
}

int main()
{
    int **graph = (int **)malloc(MAX_V * sizeof(int *));
    int i, n, k;

    printf("Enter the number of vertices:");
    scanf("%d", &n);

    printf("Enter the number of colors:");
    scanf("%d", &k);

    graph_coloring(graph, n, k);

    return 0;
}