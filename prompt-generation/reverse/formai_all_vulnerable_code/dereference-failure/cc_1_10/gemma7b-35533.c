//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

void graph_coloring(int **graph, int n, int k)
{
    int *visited = malloc(n * sizeof(int));
    int *color = malloc(n * sizeof(int));
    int i, j, max_color = -1;

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        color[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (visited[j] && graph[i][j] && color[j] == color[i])
            {
                visited[j] = 0;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        int color_found = 0;
        for (j = 0; j < k; j++)
        {
            if (!visited[j] && graph[i][j] && color[j] != -1)
            {
                color[i] = j;
                visited[j] = 1;
                color_found = 1;
                break;
            }
        }

        if (!color_found)
        {
            printf("No solution found.\n");
            return;
        }
    }

    printf("Graph colored successfully.\n");
    free(visited);
    free(color);
}

int main()
{
    int n, k;
    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of colors: ", &k);

    int **graph = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = malloc(k * sizeof(int));
    }

    printf("Enter the adjacency matrix: ");
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