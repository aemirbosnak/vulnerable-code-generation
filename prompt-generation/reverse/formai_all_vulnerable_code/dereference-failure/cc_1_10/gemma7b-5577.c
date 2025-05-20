//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void dfs(int **graph, int n, int current, int visited[])
{
    visited[current] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[current][i] && !visited[i])
        {
            dfs(graph, n, i, visited);
        }
    }
}

int main()
{
    int n, m, i, j, current, visited[MAX];
    int **graph = NULL;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(m * sizeof(int));
    }

    for (i = 0; i < m; i++)
    {
        printf("Enter the source vertex: ");
        scanf("%d", &current);

        printf("Enter the destination vertex: ");
        scanf("%d", &j);

        graph[current][j] = 1;
    }

    dfs(graph, n, 0, visited);

    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            printf("The vertex %d is not visited.\n", i);
        }
    }

    return 0;
}