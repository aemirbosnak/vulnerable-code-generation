//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10

typedef struct Graph
{
    int **adjList;
    int numVertices;
} Graph;

void graphColoring(Graph *graph)
{
    int i, j, k, color, degree[MAX_Vertices], available[MAX_Vertices];

    // Calculate the degree of each vertex
    for (i = 0; i < graph->numVertices; i++)
    {
        degree[i] = 0;
        for (j = 0; j < graph->adjList[i]; j++)
        {
            degree[i]++;
        }
    }

    // Initialize the available array
    for (i = 0; i < MAX_Vertices; i++)
    {
        available[i] = 1;
    }

    // Color each vertex
    for (i = 0; i < graph->numVertices; i++)
    {
        color = -1;
        for (k = 0; k < degree[i]; k++)
        {
            if (available[color] && color != -1)
            {
                available[color] = 0;
                break;
            }
            color++;
        }

        if (color == -1)
        {
            printf("No solution found.\n");
            exit(1);
        }

        graph->adjList[i][0] = color;
    }

    // Print the coloring
    for (i = 0; i < graph->numVertices; i++)
    {
        printf("Vertex %d colored with color %d.\n", i, graph->adjList[i][0]);
    }
}

int main()
{
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = 5;
    graph->adjList = malloc(sizeof(int *) * graph->numVertices);
    for (int i = 0; i < graph->numVertices; i++)
    {
        graph->adjList[i] = malloc(sizeof(int) * 2);
    }

    graph->adjList[0] = 1;
    graph->adjList[1] = 2;
    graph->adjList[2] = 3;
    graph->adjList[3] = 2;
    graph->adjList[4] = 1;

    graphColoring(graph);

    return 0;
}