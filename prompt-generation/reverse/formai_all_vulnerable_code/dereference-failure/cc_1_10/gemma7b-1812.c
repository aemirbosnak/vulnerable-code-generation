//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main()
{
    int n, i, j, k, count = 0;
    char **graph = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    graph = (char **)malloc(n * sizeof(char *));
    for(i = 0; i < n; i++)
    {
        graph[i] = (char *)malloc(n * sizeof(char));
        for(j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter the connections between nodes: ");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &k);
            if(k)
            {
                graph[i][j] = 1;
                count++;
            }
        }
    }

    printf("The network topology is:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("The number of connections is: %d\n", count);

    free(graph);

    return 0;
}