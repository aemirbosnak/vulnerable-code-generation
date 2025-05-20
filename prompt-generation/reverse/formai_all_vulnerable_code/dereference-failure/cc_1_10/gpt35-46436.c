//FormAI DATASET v1.0 Category: Graph representation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// function to print the adjacency matrix graph representation
void printGraph(int** graph, int vertices)
{
    int i, j;

    printf("\nAdjacency Matrix Graph Representation: \n\n  ");

    for(i = 0; i < vertices; i++)
    {
        printf("%d ", i+1);
    }

    printf("\n");

    for(i = 0; i < vertices; i++)
    {
        printf("%d ", i+1);

        for(j = 0; j < vertices; j++)
        {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int vertices;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    // allocate memory for the adjacency matrix of the graph
    int **graph = (int **) malloc(vertices * sizeof(int *));

    for(int i = 0; i < vertices; i++)
    {
        graph[i] = (int *) malloc(vertices * sizeof(int));
    }

    // initialize the adjacency matrix to all zeroes
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    // add edges to the graph
    graph[0][1] = 1;
    graph[1][2] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;
    graph[4][0] = 1;

    // print the adjacency matrix graph representation
    printGraph(graph, vertices);

    return 0;
}