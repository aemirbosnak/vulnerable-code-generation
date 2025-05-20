//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 10
#define MAX_E 20

typedef struct Edge {
    int src, dest, color;
} Edge;

void graphColoring(Edge **edges, int **visited, int **color, int v)
{
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            for (int j = 0; edges[i] && j < MAX_E; j++)
            {
                if (edges[i][j].color != -1 && visited[edges[i][j].dest] && color[edges[i][j].dest] == color[i])
                {
                    color[i] = -1;
                }
            }
            int minColor = INT_MAX;
            for (int j = 0; j < MAX_V; j++)
            {
                if (visited[j] && color[j] != -1 && color[j] < minColor)
                {
                    minColor = color[j];
                }
            }
            color[i] = minColor + 1;
        }
    }
}

int main()
{
    Edge **edges = (Edge **)malloc(MAX_V * sizeof(Edge *));
    for (int i = 0; i < MAX_V; i++)
    {
        edges[i] = (Edge *)malloc(MAX_E * sizeof(Edge));
        for (int j = 0; j < MAX_E; j++)
        {
            edges[i][j].src = -1;
            edges[i][j].dest = -1;
            edges[i][j].color = -1;
        }
    }

    int **visited = (int *)malloc(MAX_V * sizeof(int));
    for (int i = 0; i < MAX_V; i++)
    {
        visited[i] = 0;
    }

    int **color = (int *)malloc(MAX_V * sizeof(int));
    for (int i = 0; i < MAX_V; i++)
    {
        color[i] = -1;
    }

    int v = 5;
    graphColoring(edges, visited, color, v);

    for (int i = 0; i < v; i++)
    {
        printf("Vertex %d has color %d\n", i, color[i]);
    }

    free(edges);
    free(visited);
    free(color);

    return 0;
}