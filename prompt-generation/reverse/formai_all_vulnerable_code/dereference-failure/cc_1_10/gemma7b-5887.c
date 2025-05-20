//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int numVertices, int *colors)
{
    for (int i = 0; i < numVertices; i++)
    {
        colors[i] = -1;
    }

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if (graph[i][j] && colors[i] == colors[j])
            {
                colors[i] = -1;
            }
        }
    }

    for (int i = 0; i < numVertices; i++)
    {
        if (colors[i] == -1)
        {
            return;
        }
    }

    return;
}

int main()
{
    int numVertices;
    printf("Enter the number of vertices:");
    scanf("%d", &numVertices);

    int **graph = NULL;
    graph = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++)
    {
        graph[i] = (int *)malloc(numVertices * sizeof(int));
    }

    printf("Enter the adjacency matrix:");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int *colors = NULL;
    colors = (int *)malloc(numVertices * sizeof(int));

    graph_coloring(graph, numVertices, colors);

    printf("The optimal colors are:");
    for (int i = 0; i < numVertices; i++)
    {
        printf("%d ", colors[i]);
    }

    return 0;
}