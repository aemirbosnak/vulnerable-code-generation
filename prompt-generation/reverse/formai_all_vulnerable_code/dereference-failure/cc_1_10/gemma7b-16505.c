//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graph_coloring(int **graph, int n, int k)
{
    int i, j, color, available[k], visited[n], current_color = 0;

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        available[i] = 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            if (visited[graph[i][j]] && available[graph[i][j]] == 1)
            {
                available[graph[i][j]] = 0;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        color = -1;
        while (color == -1)
        {
            color = available[i];
            available[i] = 0;
            visited[i] = 1;

            for (j = 0; j < graph[i][0]; j++)
            {
                if (visited[graph[i][j]] && color == available[graph[i][j]])
                {
                    color = -1;
                }
            }
        }

        printf("Vertex %d colored with %d\n", i + 1, color);
    }
}

int main()
{
    int n, k, **graph;

    printf("Enter the number of vertices:");
    scanf("%d", &n);

    printf("Enter the number of colors:");
    scanf("%d", &k);

    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    printf("Enter the graph adjacency list:");
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