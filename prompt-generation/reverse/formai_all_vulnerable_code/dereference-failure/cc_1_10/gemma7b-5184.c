//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void topoMap(int **graph, int numVertices)
{
    int i, j, k, count = 0;
    int visited = 0;
    char **map = (char **)malloc(numVertices * sizeof(char *));
    for(i = 0; i < numVertices; i++)
    {
        map[i] = (char *)malloc(numVertices * sizeof(char));
        for(j = 0; j < numVertices; j++)
        {
            map[i][j] = 0;
        }
    }

    for(i = 0; i < numVertices; i++)
    {
        if(!visited)
        {
            visited = 1;
            for(j = 0; j < numVertices; j++)
            {
                if(graph[i][j] && map[i][j] == 0)
                {
                    map[i][j] = count++;
                }
            }
        }
    }

    for(i = 0; i < numVertices; i++)
    {
        for(j = 0; j < numVertices; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    free(map);
}

int main()
{
    int **graph = (int **)malloc(MAX * sizeof(int *));
    for(int i = 0; i < MAX; i++)
    {
        graph[i] = (int *)malloc(MAX * sizeof(int));
    }

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][3] = 1;
    graph[2][4] = 1;
    graph[3][4] = 1;

    topoMap(graph, MAX);

    return 0;
}