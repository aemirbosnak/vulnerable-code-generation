//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
    int n;
    scanf("Enter the number of vertices: ", &n);

    int **adjList = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        adjList[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjList[i][j] = 0;
        }
    }

    int edges;
    scanf("Enter the number of edges: ", &edges);

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        scanf("Enter the two vertices connected by the edge: ", &u, &v);
        adjList[u][v] = 1;
    }

    int **distance = (int *)malloc(n * sizeof(int));
    distance[0] = 0;

    for (int i = 1; i < n; i++)
    {
        distance[i] = MAX;
    }

    distance[1] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (distance[i] > distance[j] + 1)
            {
                distance[i] = distance[j] + 1;
            }
        }
    }

    int k;
    scanf("Enter the vertex to find the distance: ", &k);

    printf("The distance of vertex %d from vertex 1 is: %d\n", k, distance[k]);

    return 0;
}