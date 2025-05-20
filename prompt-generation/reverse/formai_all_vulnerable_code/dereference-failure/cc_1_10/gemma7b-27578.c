//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algorithm(int **graph, int numVertices, int **matching, int **visited)
{
    for (int i = 0; i < numVertices; i++)
    {
        if (!visited[i] && matching[i] == -1)
        {
            for (int j = 0; j < numVertices; j++)
            {
                if (graph[i][j] && visited[j] && matching[j] == -1)
                {
                    matching[i] = j;
                    visited[j] = 0;
                    break;
                }
            }
        }
    }
}

int main()
{
    int numVertices;
    scanf("Enter the number of vertices: ", &numVertices);

    int **graph = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++)
    {
        graph[i] = (int *)malloc(numVertices * sizeof(int));
    }

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("Enter the adjacency matrix element (%d, %d): ", &graph[i][j]);
        }
    }

    int **matching = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
    {
        matching[i] = -1;
    }

    int **visited = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = 0;
    }

    greedy_algorithm(graph, numVertices, matching, visited);

    int numMatched = 0;
    for (int i = 0; i < numVertices; i++)
    {
        if (matching[i] != -1)
        {
            numMatched++;
        }
    }

    printf("The number of matched vertices is: %d\n", numMatched);

    return 0;
}