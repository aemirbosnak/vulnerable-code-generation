//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int numVertices)
{
    int *colors = malloc(numVertices * sizeof(int));
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
                printf("Error: Coloring conflict.\n");
                exit(1);
            }
        }
    }

    for (int i = 0; i < numVertices; i++)
    {
        printf("Vertex %d colored with color %d.\n", i, colors[i]);
    }

    free(colors);
}

int main()
{
    int numVertices = 5;
    int **graph = malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++)
    {
        graph[i] = malloc(numVertices * sizeof(int));
    }

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][3] = 1;
    graph[2][4] = 1;

    graph_coloring(graph, numVertices);

    free(graph);

    return 0;
}