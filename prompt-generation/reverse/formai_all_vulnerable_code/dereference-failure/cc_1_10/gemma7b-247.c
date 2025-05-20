//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    int n, i, j, k, l, m, count = 0;
    char **graph = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    graph = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (char *)malloc(n * sizeof(char));
        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter the connections between nodes (pair of nodes, separated by space): ");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &k, &l);
        graph[k][l] = 1;
    }

    printf("The network topology is:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                printf("%d - ", j + 1);
            }
        }
        printf("\n");
    }

    free(graph);

    return 0;
}