//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_VERTICES 100

int main()
{
    int numVertices = 20;
    int **graph = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++)
    {
        graph[i] = (int *)malloc(numVertices * sizeof(int));
    }

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][3] = 1;
    graph[2][4] = 1;
    graph[3][4] = 1;
    graph[3][5] = 1;
    graph[4][5] = 1;
    graph[4][6] = 1;
    graph[5][6] = 1;
    graph[5][7] = 1;
    graph[6][7] = 1;
    graph[6][8] = 1;
    graph[7][8] = 1;
    graph[7][9] = 1;
    graph[8][9] = 1;
    graph[8][10] = 1;
    graph[9][10] = 1;
    graph[9][11] = 1;
    graph[10][11] = 1;
    graph[10][12] = 1;
    graph[11][12] = 1;
    graph[11][13] = 1;
    graph[12][13] = 1;
    graph[12][14] = 1;
    graph[13][14] = 1;
    graph[13][15] = 1;
    graph[14][15] = 1;

    // Network topology mapping

    int i, j, k;
    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            if (graph[i][j] > 0)
            {
                printf("%d - %d\n", i, j);
            }
        }
    }

    return 0;
}