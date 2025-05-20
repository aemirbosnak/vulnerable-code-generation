//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main()
{
    int n, i, j, k, l, m, count = 0;
    char **graph = NULL;
    char **map = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    graph = (char **)malloc(n * sizeof(char *));
    map = (char **)malloc(n * sizeof(char *));

    for (i = 0; i < n; i++)
    {
        graph[i] = (char *)malloc(n * sizeof(char));
        map[i] = (char *)malloc(n * sizeof(char));
    }

    printf("Enter the adjacency list: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%c ", &graph[i][j]);
        }
    }

    printf("Enter the map: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%c ", &map[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && map[i][j] == 'Y')
            {
                count++;
            }
        }
    }

    printf("The number of connections is: %d", count);

    return 0;
}