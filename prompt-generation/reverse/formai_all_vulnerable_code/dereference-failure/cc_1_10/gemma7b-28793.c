//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n;
    scanf("Enter the number of vertices:", &n);

    int **adjList = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        adjList[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjList[i][j] = -1;
        }
    }

    printf("Enter the adjacency list:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d ", &adjList[i][j]);
        }
    }

    int isConnected = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjList[i][j] != -1)
            {
                isConnected = 1;
            }
        }
    }

    if (isConnected)
    {
        printf("The graph is connected.\n");
    }
    else
    {
        printf("The graph is not connected.\n");
    }

    free(adjList);
}