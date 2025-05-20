//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int **adjList = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        adjList[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the adjacency list: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d ", &adjList[i][j]);
        }
    }

    int diameter = findDiameter(n, adjList);

    printf("The diameter of the tree is: %d", diameter);

    return 0;
}

int findDiameter(int n, int **adjList)
{
    int **distance = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        distance[i] = (int *)malloc(n * sizeof(int));
    }

    distance[0][0] = 0;
    distance[0][1] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            distance[i][j] = distance[j][0] + 1;
        }
    }

    int diameter = distance[n - 1][n - 1];

    return diameter;
}