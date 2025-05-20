//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

void graphColoring(int **graph, int nVertices, int k)
{
    int **color = (int *)malloc(nVertices * sizeof(int));
    for(int i = 0; i < nVertices; i++)
    {
        color[i] = -1;
    }

    int **adjList = (int *)malloc(nVertices * sizeof(int *));
    for(int i = 0; i < nVertices; i++)
    {
        adjList[i] = (int *)malloc(MAX * sizeof(int));
    }

    for(int i = 0; i < nVertices; i++)
    {
        for(int j = 0; graph[i][j] != -1; j++)
        {
            adjList[i][graph[i][j]] = 1;
        }
    }

    int visited = 0, currentColor = 0, conflict = 0;
    for(int i = 0; i < nVertices; i++)
    {
        if(color[i] == -1)
        {
            for(int j = 0; j < nVertices; j++)
            {
                if(adjList[i][j] && color[j] == currentColor)
                {
                    conflict = 1;
                }
            }

            if(!conflict)
            {
                color[i] = currentColor;
            }
            else
            {
                currentColor++;
                color[i] = currentColor;
            }

            visited++;
        }
    }

    printf("The minimum number of colors required is: %d\n", currentColor);
    printf("The coloring is: ");
    for(int i = 0; i < nVertices; i++)
    {
        printf("%d ", color[i]);
    }
    printf("\n");
}

int main()
{
    int nVertices, k;
    scanf("Enter the number of vertices: ", &nVertices);
    scanf("Enter the number of colors: ", &k);

    int **graph = (int *)malloc(nVertices * sizeof(int *));
    for(int i = 0; i < nVertices; i++)
    {
        graph[i] = (int *)malloc(nVertices * sizeof(int));
    }

    for(int i = 0; i < nVertices; i++)
    {
        for(int j = 0; j < nVertices; j++)
        {
            graph[i][j] = -1;
        }
    }

    printf("Enter the adjacency list: ");
    for(int i = 0; i < nVertices; i++)
    {
        for(int j = 0; j < nVertices; j++)
        {
            scanf("%d ", &graph[i][j]);
        }
    }

    graphColoring(graph, nVertices, k);

    return 0;
}