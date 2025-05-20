//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int main()
{
    int n, i, j, k, l, m, t, x, y;
    char **graph;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    graph = (char **)malloc(n * MAX);
    for (i = 0; i < n; i++)
    {
        graph[i] = (char *)malloc(MAX);
        for (j = 0; j < MAX; j++)
            graph[i][j] = '\0';
    }

    printf("Enter the number of edges: ");
    scanf("%d", &t);

    for (i = 0; i < t; i++)
    {
        printf("Enter the source node: ");
        scanf("%d", &x);

        printf("Enter the destination node: ");
        scanf("%d", &y);

        graph[x][y] = '1';
    }

    printf("The network topology map is:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c ", graph[i][j]);
        }

        printf("\n");
    }

    free(graph);

    return 0;
}