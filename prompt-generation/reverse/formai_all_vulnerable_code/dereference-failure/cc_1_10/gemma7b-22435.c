//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void mapper(int **graph, int n)
{
    int i, j, k, l;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(graph[i][j] != 0)
            {
                for(k = 0; k < n; k++)
                {
                    if(graph[i][k] != 0 && graph[k][j] != 0)
                    {
                        for(l = 0; l < n; l++)
                        {
                            if(graph[i][l] != 0 && graph[l][j] != 0)
                            {
                                printf("(%d, %d) -> (%d, %d)\n", i, j, l, k);
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int n = 5;
    int **graph = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    graph[0][1] = 1;
    graph[1][2] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;

    mapper(graph, n);

    return 0;
}