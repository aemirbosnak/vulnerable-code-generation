//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, target, found = 0;
    scanf("Enter the number of nodes: ", &n);
    int **graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the adjacency list: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d ", &graph[i][j]);
        }
    }

    printf("Enter the target node: ");
    scanf("%d ", &target);

    k = search(graph, n, target);

    if (k != -1)
    {
        printf("The target node is found at index %d\n", k);
    }
    else
    {
        printf("Target node not found\n");
    }

    return 0;
}

int search(int **graph, int n, int target)
{
    int i, j, k, l, found = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == target)
            {
                found = 1;
                k = i;
            }
        }
    }

    if (found)
    {
        return k;
    }
    else
    {
        return -1;
    }
}