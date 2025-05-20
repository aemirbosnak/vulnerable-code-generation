//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: interoperable
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
        scanf("Enter the endpoints of the edge:", &u, &v);
        graph[u][v] = 1;
    }

    int isConnected = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 0 && i != j)
            {
                isConnected = 0;
            }
        }
    }

    if (isConnected)
    {
        printf("The graph is connected.");
    }
    else
    {
        printf("The graph is not connected.");
    }

    return 0;
}