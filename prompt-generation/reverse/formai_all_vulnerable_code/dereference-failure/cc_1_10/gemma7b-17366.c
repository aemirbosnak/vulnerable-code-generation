//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int n, int k)
{
    int *colors = malloc(n * sizeof(int));
    int i, j, color = 0;

    for (i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            if (colors[graph[i][j]] == colors[i])
            {
                return;
            }
        }
        colors[i] = color++;
    }

    printf("The graph is colored successfully.\n");
    free(colors);
}

int main()
{
    int **graph = NULL;
    int n, k;

    printf("Enter the number of nodes:");
    scanf("%d", &n);

    printf("Enter the number of colors:");
    scanf("%d", &k);

    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    printf("Enter the adjacency list:");
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