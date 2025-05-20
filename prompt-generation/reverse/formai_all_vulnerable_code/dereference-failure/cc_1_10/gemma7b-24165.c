//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

void crypt_graph_coloring(int **graph, int numVertices, int **colors)
{
    int i, j, k, current_color = 1, available_colors[numVertices];

    // Allocate colors for each vertex
    *colors = malloc(numVertices * sizeof(int));

    // Initialize available colors for each vertex
    for (i = 0; i < numVertices; i++)
    {
        available_colors[i] = current_color;
    }

    // Iteratively assign colors to vertices
    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            if (graph[i][j] && available_colors[i] == available_colors[j])
            {
                available_colors[i] = current_color + 1;
            }
        }
        colors[i] = available_colors[i];
    }

    // Increment current color for the next vertex
    current_color++;

    // Print colors
    for (i = 0; i < numVertices; i++)
    {
        printf("Vertex %d has color %d\n", i, colors[i]);
    }
}

int main()
{
    int numVertices, numEdges;
    int **graph;
    int **colors;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    graph = malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++)
    {
        graph[i] = malloc(numVertices * sizeof(int));
    }

    printf("Enter the adjacency list: ");
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    crypt_graph_coloring(graph, numVertices, &colors);

    return 0;
}