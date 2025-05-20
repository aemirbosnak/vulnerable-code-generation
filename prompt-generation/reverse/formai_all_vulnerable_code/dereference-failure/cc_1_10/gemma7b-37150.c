//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

void graph_coloring(int **graph, int n, int k)
{
    int **visited = (int *)malloc(n * sizeof(int));
    int *color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        color[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (visited[j] && graph[i][j] && color[j] == color[i])
            {
                return;
            }
        }
        int available = -1;
        for (int j = 0; j < k; j++)
        {
            if (!visited[j] && graph[i][j])
            {
                available = j;
            }
        }
        if (available == -1)
        {
            return;
        }
        visited[available] = 1;
        color[i] = available;
    }

    printf("The graph is colored successfully.\n");
}

int main()
{
    int n, k;
    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of colors: ", &k);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    printf("Enter the adjacency matrix:\n");
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