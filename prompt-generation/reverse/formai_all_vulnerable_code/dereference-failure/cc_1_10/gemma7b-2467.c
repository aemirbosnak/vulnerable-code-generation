//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void dfs(int **graph, int current, int **visited, int **colors)
{
    int i, j, k;

    visited[current] = 1;

    for (i = 0; i < MAX; i++)
    {
        if (graph[current][i] && !visited[i])
        {
            for (j = 0; j < MAX; j++)
            {
                if (graph[i][j] && colors[i] != colors[j])
                {
                    colors[i] = colors[j];
                }
            }
            dfs(graph, i, visited, colors);
        }
    }
}

int main()
{
    int graph[MAX][MAX] = {{1, 1, 0, 1, 0},
                              {1, 1, 1, 0, 1},
                              {0, 1, 1, 1, 0},
                              {1, 0, 1, 1, 0},
                              {0, 1, 0, 0, 1}};

    int visited[MAX] = {0};

    int colors[MAX] = {0};

    colors[0] = 1;

    dfs(graph, 0, visited, colors);

    for (int i = 0; i < MAX; i++)
    {
        printf("Vertex %d has color %d\n", i, colors[i]);
    }

    return 0;
}