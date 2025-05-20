//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void findPath(int **graph, int n, int m, int currentPosition, int targetPosition)
{
    if (currentPosition == targetPosition)
    {
        printf("Path found!\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == currentPosition && graph[i][j] != -1)
            {
                findPath(graph, n, m, graph[i][j], targetPosition);
            }
        }
    }
}

int main()
{
    int n, m, currentPosition, targetPosition;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter the adjacency matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the current position: ");
    scanf("%d", &currentPosition);

    printf("Enter the target position: ");
    scanf("%d", &targetPosition);

    findPath(graph, n, m, currentPosition, targetPosition);

    return 0;
}