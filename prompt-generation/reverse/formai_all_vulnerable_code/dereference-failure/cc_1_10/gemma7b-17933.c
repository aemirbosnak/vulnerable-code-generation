//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("Enter the number of vertices:", &n);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    int edges;
    scanf("Enter the number of edges:", &edges);

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        scanf("Enter the two vertices:", &u, &v);
        graph[u][v] = 1;
    }

    int query;
    scanf("Enter the number of queries:", &query);

    for (int i = 0; i < query; i++)
    {
        int u, v;
        scanf("Enter the two vertices:", &u, &v);
        if (graph[u][v] == 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}